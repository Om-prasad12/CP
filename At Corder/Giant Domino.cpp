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
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin() + 1, arr.end() - 1);
    long long current_reach = 2LL * arr[0]; 
    int count = 1; 

    int i = 1;
    while(i < n - 1) {
        if(current_reach >= arr[n-1]) {
            break;
        }
        if(current_reach < arr[i]) {
            cout << -1 << endl;
            return;
        }
        long long best_power = arr[i];
        int j = i;
        while(j < n - 1 && arr[j] <= current_reach) {
            best_power = max(best_power, arr[j]);
            j++;
        }

        current_reach = 2LL * best_power;
        count++;
        i = j; 
    }
    if(current_reach >= arr[n-1]) {
        cout << count + 1 << endl; 
    } else {
        cout << -1 << endl;
    }
}