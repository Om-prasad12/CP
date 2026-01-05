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
   map<char,int> mpp;
   int n=s.size();
   for(int i=0;i<n;i++){
   	 mpp[s[i]]++;
   }
   int cnt=0;
   for(auto [key,value]:mpp){
   	 if(value>1) cnt++;
   }
   if(cnt>1){
   	 cout<<"YES"<<endl;
   } else{
   	 cout<<"NO"<<endl;
   }
}
