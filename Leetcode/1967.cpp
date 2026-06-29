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
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(word.contains(patterns[i])) cnt++;
        }
        return cnt;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<string> patterns(n);
    for(int i=0;i<n;i++) cin>>patterns[i];

    string word;
    cin>>word;

    Solution obj;
    cout<<obj.numOfStrings(patterns,word)<<"\n";
}