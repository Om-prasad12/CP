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
    int n,u;
    cin>>n>>u;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    double ans = -1;
    int r = 0;

    for(int i = 0; i < n; i++){
        while(r < n && arr[r] - arr[i] <= u){
            r++;
        }
        if(r - i >= 3){
            double temp = (double)(arr[r-1] - arr[i+1]) / (arr[r-1] - arr[i]);
            ans = max(ans, temp);
        }
    }

    cout << fixed << setprecision(12) << ans << "\n";
}
