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
    void recurse(vector<int>& arr, vector<int>& temp, vector<int>& vis, vector<vector<int>>& ans){
        int n=arr.size();

        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                temp.push_back(arr[i]);
                vis[i]=1;
                recurse(arr,temp,vis,ans);
                temp.pop_back();
                vis[i]=-1;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &arr) {
        int n=arr.size();

        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(n,-1);

        recurse(arr,temp,vis,ans);

        return ans;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<vector<int>> ans=obj.permute(arr);

    for(auto &v:ans){
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    }
}