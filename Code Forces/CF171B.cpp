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


void solve(){
    int n,limit;
    cin>>n>>limit;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int l=0;
    long long time=0;
    int ans=0;

    for(int r=0;r<n;r++){
        time+=arr[r];
        while(time>limit){
            time-=arr[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }

    cout<<ans<<endl;
}
