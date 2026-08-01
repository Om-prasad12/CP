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

string getPermutation(int n,int k){
    vector<int> nums;
    for(int i=1;i<=n;i++){
        nums.push_back(i);
    }

    vector<long long> fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
        if(fact[i]>INT_MAX){
            fact[i]=INT_MAX;
        }
    }

    k--;

    string ans="";

    for(int i=n;i>=1;i--){
        long long blockSize=fact[i-1];
        int index=k/blockSize;

        ans+=to_string(nums[index]);

        nums.erase(nums.begin()+index);

        k%=blockSize;
    }

    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;

    cout<<getPermutation(n,k)<<"\n";
}