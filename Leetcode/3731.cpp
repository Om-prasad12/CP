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

vector<int> findMissingElements(vector<int>& nums){
    unordered_set<int> seen(nums.begin(),nums.end());

    int mn=*min_element(nums.begin(),nums.end());
    int mx=*max_element(nums.begin(),nums.end());

    vector<int> ans;

    for(int x=mn;x<=mx;x++){
        if(!seen.count(x)){
            ans.push_back(x);
        }
    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> ans=findMissingElements(nums);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}