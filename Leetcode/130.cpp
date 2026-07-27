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
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=1;
            }
        }

        for(int j=0;j<n;j++){
            if(board[m-1][j]=='O' && !vis[m-1][j]){
                q.push({m-1,j});
                vis[m-1][j]=1;
            }
        }

        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
        }

        for(int i=1;i<m-1;i++){
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }

        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(auto [dx,dy]:dir){
                int i=x+dx;
                int j=y+dy;

                if(i>=0 && i<m && j>=0 && j<n && board[i][j]=='O' && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0)
                    board[i][j]='X';
            }
        }
    }
};

void solve() {
    int m,n;
    cin>>m>>n;

    vector<vector<char>> board(m,vector<char>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    Solution obj;
    obj.solve(board);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}