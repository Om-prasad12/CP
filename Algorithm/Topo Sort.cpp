#include<bits/stdc++.h>
using namespace std;
void solve();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution{
public:
    void dfs(int ind, stack<int>& st, vector<int> adj[], vector<int>& vis){
        vis[ind]=1;

        for(auto it:adj[ind]){
            if(vis[it]==-1){
                dfs(it,st,adj,vis);
            }
        }

        st.push(ind);
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        stack<int> st;
        vector<int> vis(V,-1);
        vector<int> ans;

        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                dfs(i,st,adj,vis);
            }
        }

        while(!st.empty()){
            int temp=st.top();
            st.pop();
            ans.push_back(temp);
        }

        return ans;
    }
};

void solve() {
    int V,E;
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> ans=obj.topoSort(V,adj);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}