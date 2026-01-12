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
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;
        for (int i = 1; i < p.size(); i++) {
            ans += max(
                abs(p[i][0] - p[i - 1][0]),
                abs(p[i][1] - p[i - 1][1])
            );
        }
        return ans;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> p(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>p[i][0]>>p[i][1];
    }

    Solution obj;
    cout<<obj.minTimeToVisitAllPoints(p)<<"\n";
}
