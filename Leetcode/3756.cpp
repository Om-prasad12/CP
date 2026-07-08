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
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        int n = s.size();

        vector<int> preSum(n), nonZero(n, 0);
        string str;

        for(int i = 0; i < n; i++) {
            int temp = s[i] - '0';
            preSum[i] = (i == 0) ? temp : preSum[i - 1] + temp;
            nonZero[i] = (i == 0) ? 0 : nonZero[i - 1];
            if(temp != 0) {
                str += s[i];
                nonZero[i]++;
            }
        }

        int m = str.size();
        vector<long long> prefX(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for(int i = 0; i < m; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            prefX[i + 1] = (prefX[i] * 10 + (str[i] - '0')) % MOD;
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];

            int sum;
            int left = (l == 0) ? 0 : nonZero[l - 1];
            int right = nonZero[r] - 1;

            long long x;

            if(left > right) {
                x = 0;
            } else {
                int len = right - left + 1;
                x = (prefX[right + 1] - (prefX[left] * pow10[len]) % MOD + MOD) % MOD;
            }

            sum = (l == 0) ? preSum[r] : preSum[r] - preSum[l - 1];
            int temp = ((long long)(x * (sum % MOD))) % MOD;
            ans.push_back(temp);
        }

        return ans;
    }
};

void solve() {
    string s;
    cin>>s;

    int q;
    cin>>q;

    vector<vector<int>> queries(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }

    Solution obj;
    vector<int> ans=obj.sumAndMultiply(s,queries);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}