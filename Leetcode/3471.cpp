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

int largestInteger(vector<int>& nums,int k){
    int n=nums.size();
    int ans=-1;

    vector<int> arr(51,0);

    int l=0,r=k-1;

    while(r<n){
        for(int i=l;i<=r;i++){
            arr[nums[i]]++;
        }

        l++;
        r++;
    }

    if(k==n){
        for(int i=50;i>=0;i--){
            if(arr[i]!=0)
                return i;
        }
    }

    for(int i=50;i>=0;i--){
        if(arr[i]==1){
            ans=i;
            break;
        }
    }

    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    cout<<largestInteger(nums,k)<<"\n";
}