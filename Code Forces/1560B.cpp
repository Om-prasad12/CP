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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}


void solve() {
   int x,y,z;
   cin>>x>>y>>z;
   int diff=abs(x-y);
   if(z<1 || z>2*diff || max(x,y)>2*diff){
   	 cout<<-1<<endl;
   } else{
   	 if(z+diff<=2*diff) cout<<z+diff<<endl;
   	 else cout<<z-diff<<endl;
   }

}