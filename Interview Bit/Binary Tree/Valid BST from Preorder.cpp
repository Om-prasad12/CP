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
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

int checkPreorder(vector<int>& arr){
    int n=arr.size();

    stack<int> st;
    int lower=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]<=lower) return 0;

        while(!st.empty() && st.top()<arr[i]){
            lower=st.top();
            st.pop();
        }

        if(!st.empty() && st.top()==arr[i]) return 0;

        st.push(arr[i]);
    }

    return 1;
}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<checkPreorder(arr)<<"\n";
}