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
    string smallestPalindrome(string s) {
        int n=s.size();

        if(n<=2) return s;

        vector<int> hash(26,0);

        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }

        string str,temp;

        for(int i=0;i<26;i++){
            while(hash[i]>=2){
                char ch='a'+i;
                str+=ch;
                hash[i]-=2;
            }
        }

        temp=str;
        reverse(temp.begin(),temp.end());

        for(int i=0;i<26;i++){
            if(hash[i]==1){
                char ch='a'+i;
                str+=ch;
            }
        }

        str+=temp;
        return str;
    }
};

void solve() {
    string s;
    cin>>s;

    Solution obj;
    cout<<obj.smallestPalindrome(s)<<"\n";
}