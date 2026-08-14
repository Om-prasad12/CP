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

TreeNode* recurse(TreeNode* root){
    if(root->left==NULL && root->right==NULL)
        return root;

    TreeNode* left=NULL;
    TreeNode* right=NULL;

    if(root->left){
        left=recurse(root->left);
        root->left=left;
    }

    if(root->right){
        right=recurse(root->right);
        root->right=right;
    }

    if(root->left!=NULL && root->right!=NULL)
        return root;

    if(root->left)
        return left;

    return right;
}

TreeNode* removeHalfNodes(TreeNode* root){
    return recurse(root);
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

void printTree(TreeNode* root){
    if(root==NULL){
        cout<<-1<<" ";
        return;
    }

    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}

void solve(){
    TreeNode* root=buildTree();

    root=removeHalfNodes(root);

    printTree(root);
    cout<<"\n";
}