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
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int curr=0;
        map<int,int> mpp;
        mpp[0]=1;
        long long validpoints=0;
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validpoints+=mpp[curr];
                curr++;
                mpp[curr]+=1;
            } else{
                curr--;
                validpoints-=mpp[curr];
                mpp[curr]++;
            }
            ans+=validpoints;
        }

        return ans;
    }
};

void solve() {
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<obj.countMajoritySubarrays(nums,target)<<"\n";
}