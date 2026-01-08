#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const long long MOD = 1000000007;

long long findSum(TreeNode* root){
    if(root==NULL) return 0;
    long long sum=0;
    long long left=findSum(root->left);
    long long right=findSum(root->right);
    sum=root->val+left+right;
    return sum;
}

long long solveUtil(TreeNode* root,long long totalSum,long long& maxAns){
    if(root==NULL) return 0;

    long long left=solveUtil(root->left, totalSum, maxAns);
    long long right=solveUtil(root->right, totalSum, maxAns);

    long long currSum=root->val + left + right;
    long long product=currSum * (totalSum - currSum);
    maxAns=max(maxAns, product);

    return currSum;
}

void solve() {

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);

    long long sum=findSum(root);
    long long maxAns=INT_MIN;
    solveUtil(root,sum,maxAns);

    cout<<(maxAns%MOD)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

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
