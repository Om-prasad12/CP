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

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],dist=roads[i][2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<int> vis(n+1,-1);
        int ans=INT_MAX;
        queue<int> q;
        q.push(1);
        vis[1]=1;

        while(!q.empty()){
            int temp=q.front();
            q.pop();

            for(int i=0;i<adj[temp].size();i++){
                auto [x,dist]=adj[temp][i];
                ans=min(ans,dist);

                if(vis[x]!=-1) continue;

                q.push(x);
                vis[x]=1;
            }
        }

        return ans;
    }
};

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> roads(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>roads[i][0]>>roads[i][1]>>roads[i][2];
    }

    Solution obj;
    cout<<obj.minScore(n,roads)<<"\n";
}