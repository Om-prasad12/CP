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

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        const long long INF = 1e14;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < 26; ++j) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = source.length();

        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v) continue;
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};

void solve() {
    string source,target;
    cin>>source>>target;

    int m;
    cin>>m;
    vector<char> original(m), changed(m);
    vector<int> cost(m);
    for(int i=0;i<m;i++){
        cin>>original[i]>>changed[i]>>cost[i];
    }

    Solution obj;
    cout<<obj.minimumCost(source,target,original,changed,cost)<<"\n";
}
