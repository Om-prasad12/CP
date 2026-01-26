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
private:
    int maxLen(vector<int>& Bars) {
        int count = 2, length = 2;
        for(int i = 1; i < Bars.size(); i++) {
            if(Bars[i] - Bars[i-1] == 1) count++;
            else count = 2;
            length = max(length, count);
        }
        return length;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side = min(maxLen(hBars), maxLen(vBars));
        return side * side; 
    }
};

void solve() {
    int n,m;
    cin>>n>>m;

    int h,v;
    cin>>h;
    vector<int> hBars(h);
    for(int i=0;i<h;i++) cin>>hBars[i];

    cin>>v;
    vector<int> vBars(v);
    for(int i=0;i<v;i++) cin>>vBars[i];

    Solution obj;
    cout<<obj.maximizeSquareHoleArea(n,m,hBars,vBars)<<"\n";
}
