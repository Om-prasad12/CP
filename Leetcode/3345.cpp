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

int smallestNumber(int n,int t){
    while(n<101){
        int digits=n;
        int product=1;

        while(digits>0){
            product*=digits%10;
            digits/=10;
        }

        if(product%t==0)
            return n;

        n++;
    }

    return 0;
}

void solve(){
    int n,t;
    cin>>n>>t;

    cout<<smallestNumber(n,t)<<"\n";
}