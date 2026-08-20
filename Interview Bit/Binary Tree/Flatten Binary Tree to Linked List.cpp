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

TreeNode* flattenTree(TreeNode* root){
    if(root==NULL)
        return NULL;

    if(root->left==NULL && root->right==NULL)
        return root;

    TreeNode* left=flattenTree(root->left);
    TreeNode* right=flattenTree(root->right);

    if(root->left){
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        left->right=temp;
    }

    if(right)
        return right;

    return left;
}

TreeNode* flatten(TreeNode* root){
    flattenTree(root);
    return root;
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
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->right;
    }
    cout<<"\n";
}

void solve(){
    TreeNode* root=buildTree();

    root=flatten(root);

    printTree(root);
}