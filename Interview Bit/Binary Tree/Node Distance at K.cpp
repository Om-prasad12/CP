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

vector<int> distanceK(TreeNode* root,int target,int k){
    map<TreeNode*,TreeNode*> mpp;
    TreeNode* targetNode=NULL;
    queue<pair<TreeNode*,TreeNode*>> q;

    q.push({root,NULL});

    while(!q.empty()){
        auto temp=q.front().first;
        auto parent=q.front().second;
        q.pop();

        mpp[temp]=parent;

        if(temp->val==target)
            targetNode=temp;

        if(temp->left)
            q.push({temp->left,temp});

        if(temp->right)
            q.push({temp->right,temp});
    }

    queue<TreeNode*> que;
    set<TreeNode*> st;

    st.insert(targetNode);
    que.push(targetNode);

    vector<int> ans;

    while(!que.empty()){
        int len=que.size();

        if(k==0){
            for(int i=0;i<len;i++){
                auto temp=que.front();
                que.pop();
                ans.push_back(temp->val);
            }
            break;
        }

        for(int i=0;i<len;i++){
            auto temp=que.front();
            que.pop();

            if(temp->left && st.find(temp->left)==st.end()){
                que.push(temp->left);
                st.insert(temp->left);
            }

            if(temp->right && st.find(temp->right)==st.end()){
                que.push(temp->right);
                st.insert(temp->right);
            }

            if(mpp[temp]!=NULL && st.find(mpp[temp])==st.end()){
                que.push(mpp[temp]);
                st.insert(mpp[temp]);
            }
        }

        k--;
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

    int target,k;
    cin>>target>>k;

    vector<int> ans=distanceK(root,target,k);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}