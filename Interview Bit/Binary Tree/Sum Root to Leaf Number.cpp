#include<bits/stdc++.h>
using namespace std;
void solve();

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

int sumNumbers(TreeNode* root){
    queue<pair<TreeNode*,long long>> q;
    q.push({root,root->val});

    int ans=0;

    while(!q.empty()){
        auto temp=q.front().first;
        auto num=q.front().second;
        q.pop();

        if(temp->left==NULL && temp->right==NULL)
            ans=(ans+num)%1003;

        if(temp->left){
            long long x=(num*10+temp->left->val)%1003;
            q.push({temp->left,x});
        }

        if(temp->right){
            long long x=(num*10+temp->right->val)%1003;
            q.push({temp->right,x});
        }
    }

    return ans;
}

TreeNode* buildTree(){
    int x;
    cin>>x;

    if(x==-1)
        return NULL;

    TreeNode* root=new TreeNode(x);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void solve(){
    TreeNode* root=buildTree();

    cout<<sumNumbers(root)<<"\n";
}