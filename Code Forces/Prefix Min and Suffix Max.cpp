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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   
   vector<int> premin(n),postmax(n);
   premin[0]=arr[0];
   for(int i=1;i<n;i++){
     premin[i]=min(arr[i],premin[i-1]);
   }
   postmax[n-1]=arr[n-1];
   for(int i=n-2;i>=0;i--){
   	postmax[i]=max(arr[i],postmax[i+1]);
   }
   string str="";
   for(int i=0;i<n;i++){
   	 if(premin[i]==arr[i] || postmax[i]==arr[i]){
   	 	str+='1';
   	 } else{
   	 	str+='0';
   	 }
   }
   cout<<str<<endl;
}
