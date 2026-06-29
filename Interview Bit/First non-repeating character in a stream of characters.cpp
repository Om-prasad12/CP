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
    string solve(string str) {
        int n=str.size();
        string ans="";
        queue<char> q;
        map<char,int> mpp;
        
        for(int i=0;i<n;i++){
            mpp[str[i]]++;
            q.push(str[i]);
            while(!q.empty() && mpp[q.front()]>1) q.pop();
            ans += (q.empty() ? '#' : q.front());
        }
        return ans;
    }
};

void solve() {
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.solve(str)<<"\n";
}