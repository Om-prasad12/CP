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
    int countCompleteComponents(int n, const vector<vector<int>>& edges) {
        vector<uint64_t> g(n);

        for(int v=0;v<n;v++)
            g[v]=1ull<<v;

        for(const auto& e:edges){
            g[e[0]]|=1ull<<e[1];
            g[e[1]]|=1ull<<e[0];
        }

        map<uint64_t,int> c;

        for(auto gv:g)
            ++c[gv];

        int ans=0;

        for(const auto& [k,v]:c)
            ans+=__builtin_popcountll(k)==v;

        return ans;
    }
};

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges(m,vector<int>(2));
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1];
    }

    Solution obj;
    cout<<obj.countCompleteComponents(n,edges)<<"\n";
}