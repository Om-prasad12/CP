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

    void pushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            node=node->left;
        }
    }

public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp=st.top();
        st.pop();

        pushAll(temp->right);

        return temp->val;
    }
};

void solve(){
    TreeNode* root=NULL;

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Insert values into BST
    for(int x:arr){
        if(root==NULL){
            root=new TreeNode(x);
            continue;
        }

        TreeNode* curr=root;

        while(true){
            if(x<curr->val){
                if(curr->left==NULL){
                    curr->left=new TreeNode(x);
                    break;
                }
                curr=curr->left;
            }
            else{
                if(curr->right==NULL){
                    curr->right=new TreeNode(x);
                    break;
                }
                curr=curr->right;
            }
        }
    }

    BSTIterator it(root);

    while(it.hasNext())
        cout<<it.next()<<" ";

    cout<<"\n";
}