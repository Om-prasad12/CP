class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        for (int nei : adj[node]) {
            if (!vis[nei]) dfs(nei, adj, vis);
        }
    }
    bool check(int time,int n,vector<vector<int>>& edges,int k){
        vector<vector<int>> adj(n);
        for (auto& e:edges) {
            if (e[2] > time) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
        }
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt>=k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>> adj(n);
        int l=0,r=0;
        for (auto& e : edges) r = max(r, e[2]);
        int ans = -1;

        while (l<=r) {
            int mid=(l+r)/2;
            if (check(mid, n, edges, k)) {
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return ans;  
    }
};