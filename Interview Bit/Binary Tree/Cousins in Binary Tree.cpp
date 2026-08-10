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

vector<int> solveTree(TreeNode* root,int target){
    queue<pair<TreeNode*,TreeNode*>> q;
    vector<int> ans;

    if(root->val==target)
        return ans;

    q.push({root,NULL});

    bool found=false;
    TreeNode* parentId=NULL;

    while(!q.empty()){
        int len=q.size();

        if(found){
            for(int i=0;i<len;i++){
                auto node=q.front().first;
                auto parent=q.front().second;
                q.pop();

                if(parent!=parentId)
                    ans.push_back(node->val);
            }

            return ans;
        }

        for(int i=0;i<len;i++){
            auto node=q.front().first;
            auto parent=q.front().second;
            q.pop();

            if(node->left){
                q.push({node->left,node});

                if(node->left->val==target){
                    parentId=node;
                    found=true;
                }
            }

            if(node->right){
                q.push({node->right,node});

                if(node->right->val==target){
                    parentId=node;
                    found=true;
                }
            }
        }
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

    int target;
    cin>>target;

    vector<int> ans=solveTree(root,target);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}