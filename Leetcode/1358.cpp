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

class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1};
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            arr[s[i]-'a']=i;
            if(arr[0]!=-1 && arr[1]!=-1 && arr[2]!=-1){
                cnt+=1+min(arr[0],min(arr[1],arr[2]));
            }
        }
        return cnt;
    }
};

void solve() {
    string s;
    cin>>s;

    Solution obj;
    cout<<obj.numberOfSubstrings(s)<<"\n";
}