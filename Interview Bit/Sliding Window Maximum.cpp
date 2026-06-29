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

class Solution {
public:
    vector<int> slidingMaximum(const vector<int> &arr, int B) {
        int n=arr.size();
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        B=min(B,n);

        for(int i=0;i<B;i++){
            pq.push({arr[i],i});
        }

        ans.push_back(pq.top().first);

        for(int i=B;i<n;i++){
            pq.push({arr[i],i});
            int left=i-B+1;
            while(!pq.empty() && pq.top().second<left) pq.pop();
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

void solve() {
    int n,B;
    cin>>n>>B;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<int> ans=obj.slidingMaximum(arr,B);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}