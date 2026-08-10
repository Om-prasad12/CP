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

bool winnerSquareGame(int n){
    vector<int> squares;

    for(int i=1;i*i<=n;i++){
        squares.push_back(i*i);
    }

    int len=squares.size();

    vector<int> dp(n+1,0);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int ind=0;

        while(dp[i]==0 && ind<len && squares[ind]<=i){
            if(dp[i-squares[ind]]==0)
                dp[i]=1;

            ind++;
        }
    }

    return dp[n];
}

void solve(){
    int n;
    cin>>n;

    cout<<winnerSquareGame(n)<<"\n";
}