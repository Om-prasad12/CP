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

int count(string str,int ind,int n,int curr,int target){
	if(ind==n && curr==target) return 1;
	if(ind==n) return 0;

	int cnt=0;
	if(str[ind]=='+'){
		cnt+=count(str,ind+1,n,curr+1,target);
	} else if(str[ind]=='-'){
		cnt+=count(str,ind+1,n,curr-1,target);
	} else{
		cnt=cnt+count(str,ind+1,n,curr-1,target)+count(str,ind+1,n,curr+1,target);;
	}
	return cnt;
}


void solve() {
   string str1,str2;
   cin>>str1>>str2;
   int target=0;
   int que=0;
   int n=str1.size();
   for(int i=0;i<n;i++){
   	if(str1[i]=='+'){
   		target++;
   	} else{
   		target--;
   	}
   	if(str2[i]=='?') que++;
   }
   int cnt=count(str2,0,n,0,target);
   double ans=(double)cnt/(pow(2,que));
   cout<<fixed << setprecision(12) <<ans<<endl;  
}