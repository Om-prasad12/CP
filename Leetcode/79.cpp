#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& board,string word,vector<vector<int>>& vis,
           int ind,int i,int j){
    if(ind==word.size()) return true;

    int m=board.size();
    int n=board[0].size();

    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    for(auto [dx,dy]:dir){
        int x=i+dx,y=j+dy;
        if(x<m && x>=0 && y<n && y>=0 && vis[x][y]==0 && board[x][y]==word[ind]){
            vis[x][y]=1;
            if(check(board,word,vis,ind+1,x,y)) return true;
            vis[x][y]=0;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board,string word){
    int m=board.size();
    int n=board[0].size();

    vector<vector<int>> vis(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0]){
                vis[i][j]=1;
                if(check(board,word,vis,1,i,j)) return true;
                vis[i][j]=0;
            }
        }
    }
    return false;
}

void solve() {
    int m,n;
    cin>>m>>n;

    vector<vector<char>> board(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    string word;
    cin>>word;

    cout<<(exist(board,word)?"true":"false")<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    int t=1;
    cin>>t;
    while(t--) solve();

    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
