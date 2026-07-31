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

        vector<int> hash(26,0);

        for(int i=0;i<n;i++){
            hash[word[i]-'a']++;
        }

        sort(hash.begin(),hash.end(),greater<int>());

        int sum1=0,sum2=0,sum3=0,sum4=0;

        for(int i=0;i<26;i++){
            if(i<8) sum1+=hash[i];
            else if(i>=8 && i<16) sum2+=hash[i];
            else if(i>=16 && i<24) sum3+=hash[i];
            else sum4+=hash[i];
        }

        int ans=1*sum1+2*sum2+3*sum3+4*sum4;
        return ans;
    }
};

void solve() {
    string word;
    cin>>word;

    Solution obj;
    cout<<obj.minimumPushes(word)<<"\n";
}