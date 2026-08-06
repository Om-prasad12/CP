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
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    if((x1+y1)%2!=(x2+y2)%2){
        cout<<-1<<"\n";
    }
    else if(x1+y1==x2+y2 || x1-y1==x2-y2){
        cout<<1<<"\n";
    }
    else{
        cout<<2<<"\n";
    }
}