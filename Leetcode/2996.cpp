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

int missingInteger(vector<int>& nums){
    int sum=nums[0];

    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]+1)
            sum+=nums[i];
        else
            break;
    }

    unordered_set<int> s(nums.begin(),nums.end());

    while(s.count(sum))
        sum++;

    return sum;
}

void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    cout<<missingInteger(nums)<<"\n";
}