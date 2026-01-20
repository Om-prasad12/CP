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
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (auto& n : nums) {
            if (n & 1) {
                auto z = ((n + 1) & ~n) >> 1;
                res.push_back(n & ~z);
            } else
                res.push_back(-1);
        }
        return res;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    vector<int> ans=obj.minBitwiseArray(nums);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}
