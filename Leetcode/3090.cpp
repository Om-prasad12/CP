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

int maximumLengthSubstring(string s){
    int n=s.size();

    if(n==2) return 2;

    vector<int> hash(26,0);
    int ans=0;

    int l=0,r=0;

    while(l<=r && r<n){
        hash[s[r]-'a']++;

        while(hash[s[r]-'a']>2){
            hash[s[l]-'a']--;
            l++;
        }

        ans=max(ans,r-l+1);
        r++;
    }

    return ans;
}

void solve(){
    string s;
    cin>>s;

    cout<<maximumLengthSubstring(s)<<"\n";
}