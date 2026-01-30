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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

const int M=1e4+1, NN=6400;
const int INF=1e9+7;

vector<int> x_pos[M];
unsigned dp[11][NN];
unsigned suffixMin[M];

class Solution {
public:
    static inline int idx(int i, int j, int c) { return i*c+j; }

    static int minCost(vector<vector<int>>& grid, int k) {
        const int r=grid.size(), c=grid[0].size(), N=r*c;

        int xMax=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                const int x=grid[i][j];
                x_pos[x].push_back(idx(i, j, c));
                xMax=max(xMax, x);
            }
        }

        for(int t=0; t<=k; t++)
            fill(dp[t], dp[t]+N, INF);

        dp[0][0]=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j <c; j++) {
                const int pos=idx(i, j, c), x=grid[i][j];
                if (i>0)
                    dp[0][pos]=
                        min(dp[0][pos], dp[0][idx(i-1, j, c)]+x);
                if (j>0)
                    dp[0][pos]=
                        min(dp[0][pos], dp[0][idx(i, j-1, c)]+x);
            }
        }

        for (int t=1; t<=k; t++) {
            unsigned currMin=INF;
            for (int x=xMax; x>=0; x--) {
                for (int idx : x_pos[x]) {
                    currMin=min(currMin, dp[t-1][idx]);
                }
                suffixMin[x]=currMin;
            }

            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    const int pos=idx(i, j, c), x=grid[i][j];

                    dp[t][pos]=min(dp[t-1][pos], suffixMin[x]);

                    if (i>0)
                        dp[t][pos]=
                            min(dp[t][pos], dp[t][idx(i-1, j, c)]+x);
                    if (j>0)
                        dp[t][pos]=
                            min(dp[t][pos], dp[t][idx(i, j-1, c)]+x);
                }
            }
        }

        int ans=dp[k][N-1];

        for (int x=1; x<=xMax; x++)
            x_pos[x].clear();

        return ans;
    }
};

void solve() {
    int r,c,k;
    cin>>r>>c>>k;
    vector<vector<int>> grid(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }

    cout<<Solution::minCost(grid,k)<<"\n";
}
