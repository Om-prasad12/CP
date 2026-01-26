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
    static int Sum(int r0, int r1, int c0, int c1, vector<vector<int>>& mat){
      return mat[r1][c1]-(r0?mat[r0-1][c1]:0)-(c0?mat[r1][c0-1]:0)+((r0>0 && c0>0)?mat[r0-1][c0-1]:0);
    }

    static int SL_W(int i0, int j0, int row, int col,
                    vector<vector<int>>& mat, int k){
        const int MM=min(row-i0, col-j0);
        int Len=0;

        for (int l=0, r=0; r<MM; r++) {
            int r0=i0+l, r1=i0+r, c0=j0+l, c1=j0+r;
            int S=Sum(r0, r1, c0, c1, mat);
            while (l<r && S>k) {
                l++;
                r0++; c0++;
                S=Sum(r0, r1, c0, c1, mat);
            }
            if (S<=k) Len=max(Len, r-l+1);
        }
        return Len;
    }

    static int maxSideLength(vector<vector<int>>& mat, int k) {
        const int row=mat.size(), col=mat[0].size();
        for (int j=1; j<col; j++) mat[0][j]+=mat[0][j-1];
        for (int i=1; i<row; i++){
            mat[i][0]+=mat[i-1][0];
            for(int j=1; j<col; j++)
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
        }

        int ans=0;
        for (int i=0; i<row; i++) {
            if (row-i<=ans) break;
            ans=max(ans, SL_W(i, 0, row, col, mat, k));
        }
        for (int j=1; j<col; j++) {
            if (col-j<=ans) break;
            ans=max(ans, SL_W(0, j, row, col, mat, k));
        }
        return ans;
    }
};

void solve() {
    int r,c,k;
    cin>>r>>c>>k;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    cout<<Solution::maxSideLength(mat,k)<<"\n";
}
