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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

class Solution {
public:
    int check(vector<vector<int>>& nums,double mid){
        int n=nums.size();
        double low=0.0,high=0.0;
        for(int i=0;i<n;i++){
            int x=nums[i][0],y=nums[i][1],l=nums[i][2];
            if(mid<=y){
                high+=(double)l*l;
            } else if(y+l<=mid){
                low+=(double)l*l;
            } else{
                low+=(double)(mid-y)*l;
                high+=(double)(y+l-mid)*l;
            }
        }
        if(high-low>1e-6) return -1;
        if(low-high>1e-6) return 1;
        return 0;
    }
    double separateSquares(vector<vector<int>>& nums) {
        int n=nums.size();
        int yl=INT_MAX,yh=INT_MIN;
        for(int i=0;i<n;i++){
            yl=min(yl,nums[i][1]);
            yh=max(yh,nums[i][1]+nums[i][2]);
        }
        double low=(double)yl,high=(double)yh;
        while(high-low>1e-6){
            double mid=low+(high-low)/2.0;
            if(check(nums,mid)<0){
                low=mid;
            } else {
                high=mid;
            }
        }
        return low+(high-low)/2.0;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    }

    Solution obj;
    cout<<fixed<<setprecision(6)<<obj.separateSquares(nums)<<"\n";
}
