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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int ans(int n){
	if(n==1) return 1;
	if(n%2==0){
		return 1+ans(n/2);
	} 
	 return 1+ans(3*n+1);
}

void solve() {
   int n;
   cin>>n;
   cout<<ans(n);  
}