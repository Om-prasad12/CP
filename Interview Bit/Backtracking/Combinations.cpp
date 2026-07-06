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
    void makecombination(vector<int>& temp, vector<vector<int>>& ans, int n, int k, int ind){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        if(ind==n+1) return;

        makecombination(temp,ans,n,k,ind+1);

        temp.push_back(ind);
        makecombination(temp,ans,n,k,ind+1);
        temp.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        makecombination(temp,ans,n,k,1);
        sort(ans.begin(),ans.end());

        return ans;
    }
};

void solve() {
    int n,k;
    cin>>n>>k;

    Solution obj;
    vector<vector<int>> ans=obj.combine(n,k);

    for(auto &v:ans){
        for(int x:v) cout<<x<<" ";
        cout<<"\n";
    }
}