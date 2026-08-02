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

bool check(long long str, vector<int>& monsters, vector<long long>& bonus){
    long long cur=str;
    int n=monsters.size();

    for(int i=0;i<n;i++){
        if(cur+bonus[i]<monsters[i]) return false;
        cur=max(0LL,cur-(long long)monsters[i]);
    }

    return true;
}

long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts){
    int n=monsters.size();
    int len=boosts.size();

    vector<long long> diff(n,0);

    for(int i=0;i<len;i++){
        int l=boosts[i][0];
        int r=boosts[i][1];
        int v=boosts[i][2];

        diff[l]+=v;
        if(r+1<n) diff[r+1]-=v;
    }

    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }

    long long l=0,r=0;

    for(int i=0;i<n;i++) r+=monsters[i];

    long long ans=0;

    while(l<=r){
        long long mid=(r-l)/2+l;

        if(check(mid,monsters,diff)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<int> monsters(n);
    for(int i=0;i<n;i++) cin>>monsters[i];

    int m;
    cin>>m;

    vector<vector<int>> boosts(m,vector<int>(3));
    for(int i=0;i<m;i++){
        cin>>boosts[i][0]>>boosts[i][1]>>boosts[i][2];
    }

    cout<<minInitialStrength(monsters,boosts)<<"\n";
}