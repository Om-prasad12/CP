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
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

int game(int start,int end,vector<int>& prefix,vector<vector<int>>& dp){
    if(start==end)
        return 0;

    if(dp[start][end]!=-1)
        return dp[start][end];

    int ans=0;

    for(int i=start;i<end;i++){
        int left;
        int right;

        if(start==0)
            left=prefix[i];
        else
            left=prefix[i]-prefix[start-1];

        right=prefix[end]-prefix[i];

        if(left<right){
            ans=max(ans,left+game(start,i,prefix,dp));
        }
        else if(left>right){
            ans=max(ans,right+game(i+1,end,prefix,dp));
        }
        else{
            ans=max(ans,left+game(start,i,prefix,dp));
            ans=max(ans,right+game(i+1,end,prefix,dp));
        }
    }

    return dp[start][end]=ans;
}

int stoneGameV(vector<int>& stoneValue){
    int n=stoneValue.size();

    vector<int> prefix(n,0);
    prefix[0]=stoneValue[0];

    for(int i=1;i<n;i++)
        prefix[i]=stoneValue[i]+prefix[i-1];

    vector<vector<int>> dp(n,vector<int>(n,-1));

    return game(0,n-1,prefix,dp);
}

void solve(){
    int n;
    cin>>n;

    vector<int> stoneValue(n);

    for(int i=0;i<n;i++)
        cin>>stoneValue[i];

    cout<<stoneGameV(stoneValue)<<"\n";
}