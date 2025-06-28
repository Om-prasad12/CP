#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
   string s,t;
   cin>>s>>t;
   int n=s.size();
   for(int i=1;i<n;i++){
      if(isupper(s[i])){
      	char x=s[i-1];
      	if(t.find(x) == string::npos){
      		cout<<"No"<<endl;
      		return;
      	}
      }
   }
   cout<<"Yes"<<endl;
}

