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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0];
        for(int i = 0; i < n - 1; i ++){
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }   
        vector<vector<int> > sol;
        for(int i = 0; i < n - 1; i ++){
            if(arr[i + 1] - arr[i] == min_diff){
                sol.push_back({arr[i], arr[i + 1]});
            }
        }
        return sol;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<vector<int>> ans = obj.minimumAbsDifference(arr);

    for(auto &p:ans){
        cout<<p[0]<<" "<<p[1]<<"\n";
    }
}