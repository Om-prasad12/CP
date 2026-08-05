#include<bits/stdc++.h>
using namespace std;
void solve();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w",stdout);
#endif
    int t=1;
    cin>>t;
    while(t--) solve();
    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}

void dfs(int n,vector<int>& row,vector<int>& col,vector<int>& left,vector<int>& right,
vector<vector<string>>& ans,vector<string>& temp,int i){
    if(i==n){
        ans.push_back(temp);
        return;
    }

    for(int j=0;j<n;j++){
        if(row[i]==0 && col[j]==0 && left[i-j+n-1]==0 && right[i+j]==0){
            row[i]++;
            col[j]++;
            left[i-j+n-1]++;
            right[i+j]++;

            temp[i][j]='Q';

            dfs(n,row,col,left,right,ans,temp,i+1);

            row[i]--;
            col[j]--;
            left[i-j+n-1]--;
            right[i+j]--;

            temp[i][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<int> row(n,0),col(n,0),left(2*n-1,0),right(2*n-1,0);
    vector<vector<string>> ans;
    vector<string> temp(n,string(n,'.'));

    dfs(n,row,col,left,right,ans,temp,0);

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<vector<string>> ans=solveNQueens(n);

    for(auto &board:ans){
        for(auto &row:board){
            cout<<row<<"\n";
        }
        cout<<"\n";
    }
}