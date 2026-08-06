#include<bits/stdc++.h>
using namespace std;

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

void solve();

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

int inorder(TreeNode* root,int& k){
    int left=-1,right=-1;

    if(root->left)
        left=inorder(root->left,k);

    k--;

    if(k==0)
        return root->val;

    if(root->right)
        right=inorder(root->right,k);

    if(left!=-1) return left;
    if(right!=-1) return right;

    return -1;
}

int kthsmallest(TreeNode* root,int k){
    return inorder(root,k);
}

TreeNode* buildTree(){
    int x;
    cin>>x;

    if(x==-1) return NULL;

    TreeNode* root=new TreeNode(x);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void solve(){
    TreeNode* root=buildTree();

    int k;
    cin>>k;

    cout<<kthsmallest(root,k)<<"\n";
}