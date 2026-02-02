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
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        while(l<r){
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
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
    cout<<obj.minPairSum(nums)<<"\n";
}