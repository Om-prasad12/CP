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

int consecutiveNodes(TreeNode* root){
    if(root==NULL)
        return 0;

    queue<TreeNode*> q;
    int cnt=0;

    q.push(root);

    while(!q.empty()){
        auto temp=q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);

            if(abs(temp->val-temp->left->val)==1)
                cnt++;
        }

        if(temp->right){
            q.push(temp->right);

            if(abs(temp->val-temp->right->val)==1)
                cnt++;
        }
    }

    return cnt;
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

    cout<<consecutiveNodes(root)<<"\n";
}