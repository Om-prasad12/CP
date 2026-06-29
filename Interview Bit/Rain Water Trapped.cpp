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
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

class Solution {
public:
    int trap(const vector<int> &arr) {
        int n=arr.size();
        vector<int> prev(n),next(n);
        priority_queue<int> pq,nq;
        for(int i=0;i<n;i++){
            if(pq.empty() || pq.top()<=arr[i]) prev[i]=-1;
            else prev[i]=pq.top();
            pq.push(arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(nq.empty() || nq.top()<=arr[i]) next[i]=-1;
            else next[i]=nq.top();
            nq.push(arr[i]);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(prev[i]==-1 || next[i]==-1) continue;
            ans+=min(prev[i],next[i]) - arr[i];
        }
        return ans;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    cout<<obj.trap(arr)<<"\n";
}