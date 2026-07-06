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
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]) st.pop();

            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }

            st.push(arr[i]);
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
    vector<int> ans=obj.nextGreater(arr);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}