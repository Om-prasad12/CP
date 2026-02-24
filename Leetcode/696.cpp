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
    int countBinarySubstrings(string s) {
        const int len = s.size();
        int count = 0;
        char prev = 'N'; char cur = s[0];
        int prev_count = 0; int cur_count = 1;
        for(int i=1;i<len;++i){
            if(s[i]!=cur){
                count += min(cur_count,prev_count);
                prev_count = cur_count;
                prev = cur;
                cur = s[i];
                cur_count = 1;
                continue;
            }
            else{
                ++cur_count;
            }
        }
        count += min(cur_count,prev_count);
        return count;
    }
};

void solve() {
    string s;
    cin>>s;

    Solution obj;
    cout<<obj.countBinarySubstrings(s)<<"\n";
}