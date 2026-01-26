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

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD=1e9+7;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        set<long long> hr;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                hr.insert(hFences[j]-hFences[i]);
            }
        }

        long long ans=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                long long d=vFences[j]-vFences[i];
                if(hr.count(d)){
                    ans=max(ans,d*d);
                }
            }
        }
        return ans%MOD;
    }
};

void solve() {
    int m,n;
    cin>>m>>n;

    int h,v;
    cin>>h;
    vector<int> hFences(h);
    for(int i=0;i<h;i++) cin>>hFences[i];

    cin>>v;
    vector<int> vFences(v);
    for(int i=0;i<v;i++) cin>>vFences[i];

    Solution obj;
    cout<<obj.maximizeSquareArea(m,n,hFences,vFences)<<"\n";
}
