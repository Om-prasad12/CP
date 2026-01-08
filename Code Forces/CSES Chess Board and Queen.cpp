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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int solve(vector<vector<int>>& board,int row,vector<int>& left,vector<int>& right,vector<int>& col){
    if(row==8) return 1;
    int cnt=0;
    for(int i=0;i<8;i++){
        if(left[row-i+7]==0 && right[i+row]==0 && col[i]==0 && board[row][i]==0){
            left[row-i+7]=1;
            right[i+row]=1;
            col[i]=1;
            cnt+=solve(board,row+1,left,right,col);
            left[row-i+7]=0;
            right[row+i]=0;
            col[i]=0;
        }
    }
    return cnt;
}

void solve() {
   vector<vector<int>> board(8,vector<int>(8,0));
   vector<int> left(15,0),right(15,0),col(8,0);
   for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        char ch;
        cin>>ch;
        if(ch=='*') board[i][j]=1;
    }
   }
   cout<<solve(board,0,left,right,col);
}