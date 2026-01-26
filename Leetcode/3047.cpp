#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        long long maxside=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=max(bottomLeft[i][0],bottomLeft[j][0]);
                int b=max(bottomLeft[i][1],bottomLeft[j][1]);
                int c=min(topRight[i][0],topRight[j][0]);
                int d=min(topRight[i][1],topRight[j][1]);
                int hight=d-b;
                int width=c-a;
                long long side=min(hight,width);
                if(side>0) maxside=max(maxside,side);
            }
        }
        return maxside*maxside;
    }
};

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

void solve() {
   
}
