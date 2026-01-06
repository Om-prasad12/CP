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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool check(vector<int>& nums,int ind,int curr,int target){
   if(ind<0 && curr==target) return true;
   if(ind<0) return false;
   bool minus=check(nums,ind-1,curr-nums[ind],target);
   bool plus=check(nums,ind-1,curr+nums[ind],target);
   return minus||plus;
}

void solve() {
   int n,w;
   cin>>n>>w;
   vector<int> nums(n);
   int sum=0;
   for(int i=0;i<n;i++){
    cin>>nums[i];
    sum+=nums[i];
   }
   if(check(nums,n-1,0,w)){
    cout<<"YES"<<endl;
   } else{
    cout<<"NO"<<endl;
   }
}