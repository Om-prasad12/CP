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

bool check(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL)
        return true;

    if(root1==NULL || root2==NULL || root1->val!=root2->val)
        return false;

    bool left=check(root1->left,root2->left);
    bool right=check(root1->right,root2->right);

    return left && right;
}

int isSameTree(TreeNode* A,TreeNode* B){
    if(A==NULL && B==NULL)
        return 1;

    if(A==NULL || B==NULL)
        return 0;

    return check(A,B);
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
    TreeNode* A=buildTree();
    TreeNode* B=buildTree();

    cout<<isSameTree(A,B)<<"\n";
}