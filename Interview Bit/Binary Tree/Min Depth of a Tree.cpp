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

int minDepth(TreeNode* root){
    if(root==NULL)
        return 0;

    queue<pair<TreeNode*,int>> q;
    q.push({root,1});

    while(!q.empty()){
        auto temp=q.front().first;
        auto num=q.front().second;
        q.pop();

        if(temp->left==NULL && temp->right==NULL)
            return num;

        if(temp->left)
            q.push({temp->left,num+1});

        if(temp->right)
            q.push({temp->right,num+1});
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

    cout<<minDepth(root)<<"\n";
}