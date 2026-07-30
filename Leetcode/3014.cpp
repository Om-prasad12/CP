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
    int minimumPushes(string word) {
        int n=word.size();

        if(n<=8){
            return n;
        }
        else if(n>8 && n<=16){
            return 8+(n-8)*2;
        }
        else if(n>16 && n<=24){
            return 24+(n-16)*3;
        }
        else{
            return 48+(n-24)*4;
        }

        return 0;
    }
};

void solve() {
    string word;
    cin>>word;

    Solution obj;
    cout<<obj.minimumPushes(word)<<"\n";
}