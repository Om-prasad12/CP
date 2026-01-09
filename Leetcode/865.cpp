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

class Solution {
public:
    TreeNode* solve(TreeNode* root,int cnt){
        if(cnt==0) return root;
        if(root==NULL) return NULL;
        TreeNode* left=solve(root->left,cnt-1);
        TreeNode* right=solve(root->right,cnt-1);
        if(left && right) return root;
        return left?left:right; 
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return root;
        int cnt=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            cnt++;
        }
        return solve(root,cnt-1);
    }
};

TreeNode* buildTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;

    TreeNode* root=new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();

        int l,r;
        cin>>l>>r;

        if(l!=-1){
            curr->left=new TreeNode(l);
            q.push(curr->left);
        }
        if(r!=-1){
            curr->right=new TreeNode(r);
            q.push(curr->right);
        }
    }
    return root;
}

void solve(){
    TreeNode* root=buildTree();
    Solution obj;
    TreeNode* ans=obj.subtreeWithAllDeepest(root);
    if(ans) cout<<ans->val<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}
