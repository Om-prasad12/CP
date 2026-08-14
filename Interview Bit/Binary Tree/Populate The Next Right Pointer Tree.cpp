#include<bits/stdc++.h>
using namespace std;
void solve();

struct TreeLinkNode{
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x){
        val=x;
        left=NULL;
        right=NULL;
        next=NULL;
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

void connect(TreeLinkNode* root){
    TreeLinkNode* curr=root;

    while(curr!=NULL){
        TreeLinkNode* prev=NULL;
        TreeLinkNode* nextroot=NULL;

        while(curr!=NULL){

            if(nextroot==NULL && curr->left!=NULL)
                nextroot=curr->left;

            if(nextroot==NULL && curr->right!=NULL)
                nextroot=curr->right;

            if(curr->left!=NULL){
                if(prev!=NULL)
                    prev->next=curr->left;

                prev=curr->left;
            }

            if(curr->right!=NULL){
                if(prev!=NULL)
                    prev->next=curr->right;

                prev=curr->right;
            }

            curr=curr->next;
        }

        curr=nextroot;
    }
}

TreeLinkNode* buildTree(){
    int x;
    cin>>x;

    if(x==-1)
        return NULL;

    TreeLinkNode* root=new TreeLinkNode(x);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}

void solve(){
    TreeLinkNode* root=buildTree();

    connect(root);

    // Print each level using next pointers
    TreeLinkNode* level=root;

    while(level!=NULL){
        TreeLinkNode* curr=level;

        while(curr!=NULL){
            cout<<curr->val<<" ";
            curr=curr->next;
        }

        cout<<"\n";

        curr=level;
        level=NULL;

        while(curr!=NULL){
            if(curr->left!=NULL){
                level=curr->left;
                break;
            }
            if(curr->right!=NULL){
                level=curr->right;
                break;
            }
            curr=curr->next;
        }
    }
}