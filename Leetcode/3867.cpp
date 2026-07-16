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
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n);

        int prefixMax = 0;

        for(int i = 0; i < n; i++){
            prefixMax = max(prefixMax, nums[i]);
            prefixGcd[i] = gcd(nums[i], prefixMax);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int left = 0;
        int right = n - 1;

        while(left < right){
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
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
    cout<<obj.gcdSum(nums)<<"\n";
}