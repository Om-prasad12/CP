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

void inorder(TreeNode* root,TreeNode*& prev,TreeNode*& first,
TreeNode*& middle,TreeNode*& last){
    if(root==NULL) return;

    inorder(root->left,prev,first,middle,last);

    if(prev!=NULL && prev->val>root->val){
        if(first==NULL){
            first=prev;
            middle=root;
        }else{
            last=root;
        }
    }

    prev=root;

    inorder(root->right,prev,first,middle,last);
}

vector<int> recoverTree(TreeNode* root){
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* middle=NULL;
    TreeNode* last=NULL;

    inorder(root,prev,first,middle,last);

    vector<int> ans;

    if(last){
        ans.push_back(last->val);
    }else{
        ans.push_back(middle->val);
    }

    ans.push_back(first->val);

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

    vector<int> ans=recoverTree(root);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}