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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

void invert(TreeNode* root){
    if(root==NULL)
        return;

    invert(root->left);
    invert(root->right);

    TreeNode* temp=root->right;
    root->right=root->left;
    root->left=temp;
}

TreeNode* invertTree(TreeNode* root){
    invert(root);
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

    root=invertTree(root);

    printTree(root);
    cout<<"\n";
}