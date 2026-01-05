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
   string s;
   cin>>s;
   int n=s.size()-1;
   int l=0,r=n;
   while(l<=r){
   	 if(s[l]=='a'+n){
   	 	l++;
   	 	n--;
   	 } else if(s[r]=='a'+n){
   	 	r--;
   	 	n--;
   	 } else{
   	 	cout<<"NO"<<endl;
   	 	return;
   	 }
   }
   cout<<"YES"<<endl;
}