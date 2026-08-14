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

void traverse(map<TreeNode*,TreeNode*>& mpp,TreeNode* root,
TreeNode*& target,int B){
    queue<TreeNode*> q;
    q.push(root);
    mpp[root]=NULL;

    while(!q.empty()){
        auto temp=q.front();
        q.pop();

        if(temp->val==B)
            target=temp;

        if(temp->left!=NULL){
            q.push(temp->left);
            mpp[temp->left]=temp;
        }

        if(temp->right!=NULL){
            q.push(temp->right);
            mpp[temp->right]=temp;
        }
    }
}

int distanceFromTarget(TreeNode* root,int B){
    map<TreeNode*,TreeNode*> mpp;
    TreeNode* target=NULL;

    traverse(mpp,root,target,B);

    queue<TreeNode*> q;
    unordered_set<TreeNode*> st;

    q.push(target);
    st.insert(target);

    int ans=-1;

    while(!q.empty()){
        int n=q.size();

        for(int i=0;i<n;i++){
            auto temp=q.front();
            q.pop();

            if(mpp[temp]!=NULL && st.find(mpp[temp])==st.end()){
                q.push(mpp[temp]);
                st.insert(mpp[temp]);
            }

            if(temp->left!=NULL && st.find(temp->left)==st.end()){
                q.push(temp->left);
                st.insert(temp->left);
            }

            if(temp->right!=NULL && st.find(temp->right)==st.end()){
                q.push(temp->right);
                st.insert(temp->right);
            }
        }

        ans++;
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

    int B;
    cin>>B;

    cout<<distanceFromTarget(root,B)<<"\n";
}