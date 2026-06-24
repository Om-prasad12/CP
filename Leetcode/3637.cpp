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
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), peak = n - 1, valley = 0;

        for (int i = 0; i < n - 1; i++) {
            if (peak == n - 1 && nums[i] >= nums[i + 1])
                peak = i;
            if (valley == 0 && nums[n - 1 - i] <= nums[n - 2 - i])
                valley = n - 1 - i;
            if (peak < valley)
                return isDecreasing(nums, peak, valley);
        }

        return false;
    }

    bool isDecreasing(vector<int>& A, int a, int b) {
        if (a == 0 || b == A.size() - 1) return false;
        for (int i = a; i < b; i++)
            if (A[i] <= A[i + 1]) return false;
        
        return true;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<(obj.isTrionic(nums) ? "true" : "false")<<"\n";
}
