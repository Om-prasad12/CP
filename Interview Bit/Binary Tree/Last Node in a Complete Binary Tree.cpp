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

int lastNode(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int ans=-1;

    while(!q.empty()){
        auto temp=q.front();
        q.pop();

        ans=temp->val;

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }

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

    cout<<lastNode(root)<<"\n";
}