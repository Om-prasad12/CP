#include<bits/stdc++.h>
using namespace std;
void solve();

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
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

long long count(long long mid,vector<int>& coins){
    int n=coins.size();
    long long ans=0;

    for(int mask=1;mask<(1<<n);mask++){
        long long lcm=1;
        int bits=0;
        bool valid=true;

        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                bits++;

                long long g=__gcd(lcm,(long long)coins[i]);

                if(lcm/g>mid/coins[i]){
                    valid=false;
                    break;
                }

                lcm=(lcm/g)*coins[i];
            }
        }

        if(!valid || lcm>mid) continue;

        if(bits%2==1)
            ans+=mid/lcm;
        else
            ans-=mid/lcm;
    }

    return ans;
}

long long findKthSmallest(vector<int>& coins,int k){
    int n=coins.size();

    sort(coins.begin(),coins.end());

    vector<int> temp;

    for(int i=0;i<n;i++){
        bool redundant=false;

        for(int j=0;j<temp.size();j++){
            if(coins[i]%temp[j]==0){
                redundant=true;
                break;
            }
        }

        if(!redundant)
            temp.push_back(coins[i]);
    }

    coins=temp;

    long long low=1;
    long long high=1LL*coins[0]*k;
    long long ans=high;

    while(low<=high){
        long long mid=low+(high-low)/2;

        if(count(mid,coins)>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> coins(n);

    for(int i=0;i<n;i++)
        cin>>coins[i];

    cout<<findKthSmallest(coins,k)<<"\n";
}