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

int game(int ind,int m,vector<int>& piles,vector<int>& prefix,
vector<vector<int>>& dp){
    int n=piles.size();

    if(ind>=n) return 0;

    int ans=0;

    for(int x=1;x<=2*m && ind+x<=n;x++){
        int newm=max(m,x);
        int opponent;

        if(dp[ind+x][newm]!=-1){
            opponent=dp[ind+x][newm];
        }else{
            opponent=game(ind+x,newm,piles,prefix,dp);
            dp[ind+x][newm]=opponent;
        }

        int total_remaining=prefix[n-1]-(ind>0?prefix[ind-1]:0);

        ans=max(ans,total_remaining-opponent);
    }

    return ans;
}

int stoneGameII(vector<int>& piles){
    int n=piles.size();

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    vector<int> prefix(n,0);

    prefix[0]=piles[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+piles[i];
    }

    return game(0,1,piles,prefix,dp);
}

void solve(){
    int n;
    cin>>n;

    vector<int> piles(n);
    for(int i=0;i<n;i++)
        cin>>piles[i];

    cout<<stoneGameII(piles)<<"\n";
}