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
    void recurse(string str, string& ans, int k){
        if(str>ans) ans=str;

        if(k==0) return;

        int n=str.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(str[i],str[j]);
                recurse(str,ans,k-1);
                swap(str[i],str[j]);
            }
        }
    }

    string solve(string str, int B) {
        int n=str.size();
        string ans=str;

        recurse(str,ans,B);

        return ans;
    }
};

void solve() {
    string str;
    int B;
    cin>>str>>B;

    Solution obj;
    cout<<obj.solve(str,B)<<"\n";
}