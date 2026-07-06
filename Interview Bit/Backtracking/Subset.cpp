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
    void formSubset(vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans, int ind){
        if(ind==arr.size()){
            ans.push_back(temp);
            return;
        }

        formSubset(arr,temp,ans,ind+1);

        temp.push_back(arr[ind]);
        formSubset(arr,temp,ans,ind+1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        vector<int> temp;

        sort(arr.begin(),arr.end());
        formSubset(arr,temp,ans,0);
        sort(ans.begin(),ans.end());

        return ans;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<vector<int>> ans=obj.subsets(arr);

    for(auto &v:ans){
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    }
}