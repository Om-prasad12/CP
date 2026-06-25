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
    int largestRectangleArea(vector<int> &arr) {
        int n=arr.size();
        stack<int> pt,nt;
        vector<int> prev(n),next(n);

        for(int i=0;i<n;i++){
            while(!pt.empty() && arr[pt.top()]>=arr[i]) pt.pop();
            if(pt.empty()) prev[i]=-1;
            else prev[i]=pt.top();
            pt.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!nt.empty() && arr[nt.top()]>=arr[i]) nt.pop();
            if(nt.empty()) next[i]=n;
            else next[i]=nt.top();
            nt.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int len=next[i]-prev[i]-1;
            ans=max(ans,len*arr[i]);
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
    cout<<obj.largestRectangleArea(arr)<<"\n";
}