#include<bits/stdc++.h>
using namespace std;
void solve();

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

bool checkDivisibility(int n){
    int digit_sum=0;
    int digit_product=1;

    int num=n;

    while(num){
        int temp=num%10;
        num/=10;
        digit_sum+=temp;
        digit_product*=temp;
    }

    return n%(digit_sum+digit_product)==0;
}

void solve(){
    int n;
    cin>>n;

    cout<<checkDivisibility(n)<<"\n";
}