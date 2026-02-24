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
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
                }
            }
        }
        return res;
    }
};

void solve() {
    int turnedOn;
    cin>>turnedOn;

    Solution obj;
    vector<string> ans=obj.readBinaryWatch(turnedOn);

    for(auto &s:ans) cout<<s<<"\n";
}