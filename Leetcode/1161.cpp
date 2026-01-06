#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=-1;
        int lvl=1;
        long long maxSum=LLONG_MIN;

        while(!q.empty()){
            int l=q.size();
            long long sum=0;
            for(int i=0;i<l;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(sum>maxSum){
                ans=lvl;
                maxSum=sum;
            }
            lvl++;
        }
        return ans;
    }
};

// build tree from level order input
TreeNode* buildTree(vector<int>& arr){
    if(arr[0]==-1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<arr.size()){
        TreeNode* curr = q.front();
        q.pop();

        if(arr[i]!=-1){
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i<arr.size() && arr[i]!=-1){
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    TreeNode* root = buildTree(arr);

    Solution ob;
    cout<<ob.maxLevelSum(root)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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
