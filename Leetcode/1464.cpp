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
    // cin>>t;
    while(t--) solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curMax = nums[0];

        for(int i = 1; i < n; i++) {
            ans = max(ans, (curMax - 1) * (nums[i] - 1));
            curMax = max(curMax, nums[i]);
        }

        return ans;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<obj.maxProduct(nums)<<"\n";
}