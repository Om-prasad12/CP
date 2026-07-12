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
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int curRank = 1;

        for(int x : sorted){
            if(!rank.count(x))
                rank[x] = curRank++;
        }

        vector<int> ans;
        ans.reserve(arr.size());

        for(int x : arr)
            ans.push_back(rank[x]);

        return ans;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<int> ans = obj.arrayRankTransform(arr);

    for(int x : ans) cout<<x<<" ";
    cout<<"\n";
}