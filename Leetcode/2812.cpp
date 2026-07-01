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
    int check(vector<vector<int>>& dist){
        int n=dist.size();

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));

        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        pq.push({dist[0][0],{0,0}});

        while(!pq.empty()){
            auto [safe,p]=pq.top();
            auto [i,j]=p;
            pq.pop();

            if(vis[i][j]) continue;
            vis[i][j]=1;

            if(i==n-1 && j==n-1) return safe;

            for(auto [dx,dy]:dir){
                int x=i+dx,y=j+dy;

                if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                    pq.push({min(safe,dist[x][y]),{x,y}});
                }
            }
        }

        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        if(grid[0][0]==1 && grid[n-1][n-1]==1) return 0;

        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,pair<int,int>>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    dist[i][j]=0;
                }
            }
        }

        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [len,p]=q.front();
            auto [i,j]=p;
            q.pop();

            for(auto [dx,dy]:dir){
                int x=i+dx,y=j+dy;
                if(x>=0 && x<n && y>=0 && y<n && dist[x][y]==-1){
                    dist[x][y]=len+1;
                    q.push({len+1,{x,y}});
                }
            }
        }

        return check(dist);
    }
};

void solve() {
    int n;
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    Solution obj;
    cout<<obj.maximumSafenessFactor(grid)<<"\n";
}