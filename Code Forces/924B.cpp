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


void solve() {
    int n,u;
    cin>>n>>u;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double ans=-1;
    int l=0;
    for(int i=2;i<n;i++){
        while(l<i && arr[i]-arr[l]>u){
            l++;
        }
        if(i-l>=2){
            double temp=(double)(arr[i]-arr[l+1])/(arr[i]-arr[l]);
            ans=max(ans,temp);
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}