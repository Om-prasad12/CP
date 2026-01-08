#include<bits/stdc++.h>
using namespace std;

int solveUtil(vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp,int i,int j){
    if(i==nums1.size()){
        if(j==0) return INT_MIN;
        return 0;
    }
    if(j==nums2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int notPick=solveUtil(nums1,nums2,dp,i+1,j);
    int pick=INT_MIN;

    for(int k=j;k<nums2.size();k++){
        pick=max(pick,nums1[i]*nums2[k]+solveUtil(nums1,nums2,dp,i+1,k+1));
    }
    return dp[i][j]=max(notPick,pick);
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++) cin>>nums1[i];
    for(int i=0;i<m;i++) cin>>nums2[i];

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<solveUtil(nums1,nums2,dp,0,0)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t=1;
    cin>>t;
    while(t--) solve();

    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
