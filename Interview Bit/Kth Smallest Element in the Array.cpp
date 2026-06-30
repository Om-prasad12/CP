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
    while(t--) solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution {
public:
    int kthsmallest(const vector<int> &arr, int b) {
        int n=arr.size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,arr[i]);
            high=max(high,arr[i]);
        }

        int mid;
        int cnt=0;
        while(low<=high){
            cnt=0;
            mid=(high-low)/2+low;
            for(int i=0;i<n;i++){
                if(arr[i]<=mid) cnt++;
            }
            if(cnt<b){
                low=mid+1;
            } else{
                high=mid-1;
            }
        }
        return low;
    }
};

void solve() {
    int n,b;
    cin>>n>>b;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    cout<<obj.kthsmallest(arr,b)<<"\n";
}