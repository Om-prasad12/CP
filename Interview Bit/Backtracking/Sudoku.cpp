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
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

bool sudoku(vector<vector<char>>& board,
            vector<vector<int>>& row,
            vector<vector<int>>& col,
            vector<vector<int>>& box){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            if(board[i][j]=='.'){

                int b=(i/3)*3+j/3;

                for(int num=1;num<=9;num++){

                    if(row[i][num]==0 &&
                       col[j][num]==0 &&
                       box[b][num]==0){

                        board[i][j]=num+'0';
                        row[i][num]++;
                        col[j][num]++;
                        box[b][num]++;

                        if(sudoku(board,row,col,box))
                            return true;

                        board[i][j]='.';
                        row[i][num]--;
                        col[j][num]--;
                        box[b][num]--;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solve(){
    vector<vector<char>> board(9,vector<char>(9));

    for(int i=0;i<9;i++){
        string s;
        cin>>s;
        for(int j=0;j<9;j++){
            board[i][j]=s[j];
        }
    }

    vector<vector<int>> row(9,vector<int>(10,0));
    vector<vector<int>> col(9,vector<int>(10,0));
    vector<vector<int>> box(9,vector<int>(10,0));

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int x=board[i][j]-'0';
                row[i][x]++;
                col[j][x]++;

                int b=(i/3)*3+j/3;
                box[b][x]++;
            }
        }
    }

    sudoku(board,row,col,box);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}