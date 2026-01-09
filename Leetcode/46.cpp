#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void helper(vector<int>& nums,vector<int>& vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                vis[i]=1;
                temp.push_back(nums[i]);
                helper(nums,vis);
                vis[i]=0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        helper(nums,vis);
        return ans;
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    vector<vector<int>> res=obj.permute(nums);

    for(auto &v:res){
        for(auto &x:v) cout<<x<<" ";
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    int t=1;
    cin>>t;
    while(t--) solve();

    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
