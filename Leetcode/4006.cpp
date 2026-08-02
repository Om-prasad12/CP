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

int countValidPrefixes(string s){
    int n=s.size();
    int diff=0,cnt=0;

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            diff++;
        }else{
            diff--;
        }

        if(diff<2 && diff>-2)
            cnt++;
    }

    return cnt;
}

void solve(){
    string s;
    cin>>s;

    cout<<countValidPrefixes(s)<<"\n";
}