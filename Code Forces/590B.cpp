#include<bits/stdc++.h>
#define ll long long
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
    int n;
    ll d;
    cin>>n>>d;

    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr.begin(),arr.end());

    int l=0;
    ll curr=0, ans=0;

    for(int i=0;i<n;i++){
        curr+=arr[i].second;
        while(arr[i].first-arr[l].first>=d){
            curr-=arr[l].second;
            l++;
        }
        ans=max(ans,curr);
    }

    cout<<ans<<endl;
}