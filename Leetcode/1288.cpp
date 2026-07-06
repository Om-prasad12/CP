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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });

        int cnt=0;
        int maxEnd=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][1]<=maxEnd)
                cnt++;
            else
                maxEnd=intervals[i][1];
        }

        return n-cnt;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }

    Solution obj;
    cout<<obj.removeCoveredIntervals(intervals)<<"\n";
}