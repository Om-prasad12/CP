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
    int gcdOfOddEvenSums(int n) {
        int oddSum = n + n * (n - 1) * 2;
        int evenSum = 2 * n + n * (n - 1) * 2;
        return gcd(oddSum, evenSum);
    }
};

void solve() {
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.gcdOfOddEvenSums(n)<<"\n";
}