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

int longestConsecutive(vector<int>& arr){
    int n=arr.size();

    unordered_set<int> st;

    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    int ans=1;

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int x=it+1;
            int curr=1;

            while(st.find(x)!=st.end()){
                x++;
                curr++;
            }

            ans=max(ans,curr);
        }
    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<longestConsecutive(arr)<<"\n";
}