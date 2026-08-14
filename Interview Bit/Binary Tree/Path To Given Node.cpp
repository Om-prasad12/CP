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

bool findpath(TreeNode* root,int target,vector<int>& ans){
    if(root==NULL) return false;

    if(root->val==target)
        return true;

    if(root->left){
        ans.push_back(root->left->val);

        if(findpath(root->left,target,ans))
            return true;
        else
            ans.pop_back();
    }

    if(root->right){
        ans.push_back(root->right->val);

        if(findpath(root->right,target,ans))
            return true;
        else
            ans.pop_back();
    }

    return false;
}

vector<int> findPath(TreeNode* root,int target){
    vector<int> ans;

    if(root==NULL)
        return ans;

    ans.push_back(root->val);
    findpath(root,target,ans);

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

    int target;
    cin>>target;

    vector<int> ans=findPath(root,target);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}