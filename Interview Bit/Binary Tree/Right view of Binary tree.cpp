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

void inorder(TreeNode* root,int ind,vector<int>& ans){
    if(root==NULL) return;

    if(ans.size()>ind){
        ans[ind]=root->val;
    }else{
        ans.push_back(root->val);
    }

    inorder(root->left,ind+1,ans);
    inorder(root->right,ind+1,ans);
}

vector<int> treeDepthValues(TreeNode* root){
    vector<int> ans;
    inorder(root,0,ans);
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

    vector<int> ans=treeDepthValues(root);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}