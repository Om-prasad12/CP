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
    int maxSpecialProduct(vector<int> &arr) {
        int MOD = 1e9+7;
        int n=arr.size();
        vector<long long> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(st.empty()) ans[i]=(ans[i]*0);
            else ans[i]=(1LL*ans[i]*st.top());
            st.push(i);
        }

        long long maxAns=0;
        for(int i=0;i<n;i++){
            maxAns=max(maxAns,ans[i]);
        }

        return maxAns%MOD;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    cout<<obj.maxSpecialProduct(arr)<<"\n";
}