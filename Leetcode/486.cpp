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

bool predictTheWinner(vector<int>& nums){
    int n=nums.size();

    vector<vector<int>> dp(n,vector<int>(n));

    for(int i=0;i<n;i++)
        dp[i][i]=nums[i];

    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;

            int takeLeft=nums[i]-dp[i+1][j];
            int takeRight=nums[j]-dp[i][j-1];

            dp[i][j]=max(takeLeft,takeRight);
        }
    }

    return dp[0][n-1]>=0;
}

void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    cout<<predictTheWinner(nums)<<"\n";
}