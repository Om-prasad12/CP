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

class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp=st.top();
        st.pop();

        if(reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }

private:
    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);

            if(reverse)
                node=node->right;
            else
                node=node->left;
        }
    }
};

int t2Sum(TreeNode* root,int k){
    if(root==NULL) return 0;

    BSTIterator l(root,false);
    BSTIterator r(root,true);

    int i=l.next();
    int j=r.next();

    while(i<j){
        if(i+j==k)
            return 1;

        if(i+j<k){
            if(!l.hasNext())
                break;
            i=l.next();
        }
        else{
            if(!r.hasNext())
                break;
            j=r.next();
        }
    }

    return 0;
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

    int k;
    cin>>k;

    cout<<t2Sum(root,k)<<"\n";
}