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
   int n,j,k;
   cin>>n>>j>>k;
   int maxNo=INT_MIN;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
   	 cin>>arr[i];
   	 maxNo=max(maxNo,arr[i]);
   }
   if(k>1){
   	cout<<"yes"<<endl;
   } else if(maxNo==arr[j-1]){
     cout<<"Yes"<<endl;
   } else{
   	cout<<"No"<<endl;
   }

}
