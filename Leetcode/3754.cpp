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
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long place = 1;

        while(n > 0){
            int d = n % 10;
            if(d != 0){
                x = d * place + x;
                place *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};

void solve() {
    int n;
    cin>>n;

    Solution obj;
    cout<<obj.sumAndMultiply(n)<<"\n";
}