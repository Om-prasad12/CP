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

vector<int> resultArray(vector<int>& nums){
    int n=nums.size();

    vector<int> ans,temp;

    ans.push_back(nums[0]);
    temp.push_back(nums[1]);

    int l1=nums[0],l2=nums[1];

    for(int i=2;i<n;i++){
        if(l1>l2){
            ans.push_back(nums[i]);
            l1=nums[i];
        }
        else{
            temp.push_back(nums[i]);
            l2=nums[i];
        }
    }

    ans.insert(ans.end(),temp.begin(),temp.end());

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> ans=resultArray(nums);

    for(int x:ans)
        cout<<x<<" ";

    cout<<"\n";
}