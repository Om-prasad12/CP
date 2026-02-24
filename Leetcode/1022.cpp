#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int covertToNum(string temp){
        return stoi(temp,nullptr,2);
    }

    void countSum(TreeNode* root,string& temp,int& ans){
        if(root==NULL) return;
        temp.push_back(root->val+'0');
        if(root->left==NULL && root->right==NULL){
            ans+=covertToNum(temp);
        }
        countSum(root->left,temp,ans);
        countSum(root->right,temp,ans);
        temp.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {
        string temp="";
        int ans=0;
        countSum(root,temp,ans);
        return ans;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<TreeNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){
        if(a[i]!=-1) nodes[i]=new TreeNode(a[i]);
    }
    for(int i=0;i<n;i++){
        if(nodes[i]){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    Solution obj;
    cout<<obj.sumRootToLeaf(nodes[0])<<"\n";
}