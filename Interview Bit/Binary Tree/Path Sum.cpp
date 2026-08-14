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

int hasPathSum(TreeNode* root,int target){
    if(root==NULL)
        return 0;

    queue<pair<TreeNode*,long long>> q;
    q.push({root,root->val});

    while(!q.empty()){
        auto temp=q.front().first;
        auto sum=q.front().second;
        q.pop();

        if(sum==target && temp->left==NULL && temp->right==NULL)
            return 1;

        if(temp->left){
            long long x=sum+temp->left->val;
            q.push({temp->left,x});
        }

        if(temp->right){
            long long x=sum+temp->right->val;
            q.push({temp->right,x});
        }
    }

    return 0;
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

    int target;
    cin>>target;

    cout<<hasPathSum(root,target)<<"\n";
}