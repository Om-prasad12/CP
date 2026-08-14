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

void dfs(TreeNode* root,int target,int sum,vector<vector<int>>& ans,
vector<int>& temp){
    if(sum==target && root->left==NULL && root->right==NULL){
        ans.push_back(temp);
        return;
    }

    if(root->left){
        temp.push_back(root->left->val);
        dfs(root->left,target,sum+root->left->val,ans,temp);
        temp.pop_back();
    }

    if(root->right){
        temp.push_back(root->right->val);
        dfs(root->right,target,sum+root->right->val,ans,temp);
        temp.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root,int target){
    vector<vector<int>> ans;
    vector<int> temp;

    if(root==NULL)
        return ans;

    temp.push_back(root->val);
    dfs(root,target,root->val,ans,temp);

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

    vector<vector<int>> ans=pathSum(root,target);

    for(auto &v:ans){
        for(int x:v)
            cout<<x<<" ";
        cout<<"\n";
    }
}