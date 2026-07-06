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
    void makeSubset(vector<int>& arr, vector<int>& temp, set<vector<int>>& st, int ind, int sum, int target){
        if(sum==target){
            st.insert(temp);
            return;
        }

        if(ind==arr.size()) return;

        makeSubset(arr,temp,st,ind+1,sum,target);

        if(sum+arr[ind]<=target){
            temp.push_back(arr[ind]);
            makeSubset(arr,temp,st,ind,sum+arr[ind],target);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int B) {
        int n=arr.size();
        set<vector<int>> st;
        vector<int> temp;

        sort(arr.begin(),arr.end());

        makeSubset(arr,temp,st,0,0,B);

        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
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
    vector<vector<int>> ans=obj.combinationSum(arr,B);

    for(auto &v:ans){
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    }
}