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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int countOnes(vector<int>& nums,int i){
	int cnt=0;
	int n=nums.size();
	while(i>=0 && nums[i]==1){
		i--;
		cnt++;
	}
	return cnt;
}
void solve() {
   int n;
   cin>>n;
   vector<int> nums(n);
   for(int i=0;i<n;i++) cin>>nums[i];

   if(nums[n-1]==1){
   	cout<<"NO"<<endl;
   	return;
   }	
   vector<int> ans;
   for(int i=n-1;i>=0;i--){
   	if(nums[i]==0){
   		ans.push_back(0);
   	} else{
   		int cnt=countOnes(nums,i);
   		for(int j=0;j<cnt-1;j++) ans.push_back(0);
   		ans.push_back(cnt);
   		i=i-cnt+1;	
   	}
   }
   cout<<"YES"<<endl;
   for(int i=0;i<n;i++){
   	cout<<ans[i]<<" ";
   }
   cout<<endl;
}