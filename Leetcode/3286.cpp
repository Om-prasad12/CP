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
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        priority_queue<pair<int,pair<int,int>>> q;

        health -= grid[0][0];
        if (health <= 0) return false;

        q.push({health, {0, 0}});
        vis[0][0] = health;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [h, p] = q.top();
            auto [i, j] = p;
            q.pop();

            if (h < vis[i][j]) continue;

            if (i == m-1 && j == n-1)
                return true;

            for (auto [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int nh = h;
                    if (grid[x][y] == 1) nh--;

                    if (nh > 0 && nh > vis[x][y]) {
                        vis[x][y] = nh;
                        q.push({nh, {x, y}});
                    }
                }
            }
        }

        return false;
    }
};

void solve() {
    int m,n,health;
    cin>>m>>n>>health;

    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    Solution obj;
    cout<<(obj.findSafeWalk(grid,health) ? "true" : "false")<<"\n";
}