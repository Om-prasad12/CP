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

int checkBalanced(TreeNode* root){
    if(root==NULL)
        return 0;

    int left=0,right=0;

    left=checkBalanced(root->left);
    right=checkBalanced(root->right);

    if(left==-1 || right==-1)
        return -1;

    if(abs(left-right)>1)
        return -1;

    return max(left,right)+1;
}

int isBalanced(TreeNode* root){
    int ans=checkBalanced(root);

    if(ans==-1)
        return 0;

    return 1;
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

    cout<<isBalanced(root)<<"\n";
}