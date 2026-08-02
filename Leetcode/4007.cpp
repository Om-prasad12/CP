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

int maximumWidth(vector<int>& planks){
    int n=planks.size();

    unordered_map<int,int> hash;

    for(int i=0;i<n;i++){
        hash[planks[i]]++;
    }

    unordered_map<int,int> ps;

    for(auto i=hash.begin();i!=hash.end();i++){
        for(auto j=i;j!=hash.end();j++){
            if(i==j){
                if(i->second>=2)
                    ps[i->first*2]+=i->second/2;
            }
            else{
                ps[i->first+j->first]+=min(i->second,j->second);
            }
        }
    }

    int ans=0;

    for(auto &x:hash){
        int cnt=x.second;
        if(ps.count(x.first))
            cnt+=ps[x.first];
        ans=max(ans,cnt);
    }

    for(auto &x:ps){
        int cnt=x.second;
        if(hash.count(x.first))
            cnt+=hash[x.first];
        ans=max(ans,cnt);
    }

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<int> planks(n);
    for(int i=0;i<n;i++) cin>>planks[i];

    cout<<maximumWidth(planks)<<"\n";
}