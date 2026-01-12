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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            if(nums[l]+nums[r]>target){
                r--;
            } else if(nums[l]+nums[r]<target){
                l++;
            } else{
                break;
            }
        }
        return {l+1,r+1};
    }
};

void solve() {
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    vector<int> ans=obj.twoSum(nums,target);

    cout<<ans[0]<<" "<<ans[1]<<"\n";
}
