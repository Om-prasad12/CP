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

void traverse(TreeNode* root1,TreeNode* root2){
    if(root1->left!=NULL && root2->left!=NULL){
        root1->left->val+=root2->left->val;
        traverse(root1->left,root2->left);
    }
    else if(root1->left==NULL){
        root1->left=root2->left;
    }

    if(root1->right!=NULL && root2->right!=NULL){
        root1->right->val+=root2->right->val;
        traverse(root1->right,root2->right);
    }
    else if(root1->right==NULL){
        root1->right=root2->right;
    }
}

TreeNode* mergeTrees(TreeNode* root1,TreeNode* root2){
    if(root1==NULL)
        return root2;

    if(root2==NULL)
        return root1;

    root1->val+=root2->val;
    traverse(root1,root2);

    return root1;
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
    TreeNode* root1=buildTree();
    TreeNode* root2=buildTree();

    TreeNode* root=mergeTrees(root1,root2);

    printTree(root);
    cout<<"\n";
}