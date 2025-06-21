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
   int n;
   cin>>n;
   vector<int> arr(n-1);
   for(int i=0;i<n-1;i++) cin>>arr[i];

   for(int i=0;i<n-1;i++){
   	int temp=0;
   	 for(int j=i;j<n-1;j++){
       temp+=arr[j];
       cout<<temp<<" ";
   	 }
   	 cout<<endl;
   }
}
