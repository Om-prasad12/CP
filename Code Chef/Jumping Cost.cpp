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

void solve(){
    int n;
    cin>>n;

    vector<long long> a(n+1),dp(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    long long ans=0;
    long long best=1;

    for(int j=2;j<=n;j++){
        dp[j]=a[j]-j+best;
        ans=max(ans,dp[j]);
        best=max(best,dp[j]+j);
    }

    cout<<ans<<"\n";
}