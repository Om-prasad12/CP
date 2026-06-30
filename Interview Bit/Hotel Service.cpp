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
    vector<int> nearestHotel(vector<vector<int>> &arr, vector<vector<int>> &query) {
        int N=arr.size();
        int M=arr[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(N,vector<int>(M,-1));

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==1){
                    q.push({0,{i,j}});
                    dist[i][j]=0;
                }
            }
        }

        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int cnt=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();

            for(auto [x,y]:dir){
                int dx=i+x,dy=j+y;
                if(dx>=0 && dx<N && dy>=0 && dy<M && dist[dx][dy]==-1){
                    dist[dx][dy]=cnt+1;
                    q.push({cnt+1,{dx,dy}});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<query.size();i++){
            int x=query[i][0]-1;
            int y=query[i][1]-1;
            ans.push_back(dist[x][y]);
        }
        return ans;
    }
};

void solve() {
    int N,M;
    cin>>N>>M;

    vector<vector<int>> arr(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }

    int Q;
    cin>>Q;
    vector<vector<int>> query(Q,vector<int>(2));
    for(int i=0;i<Q;i++){
        cin>>query[i][0]>>query[i][1];
    }

    Solution obj;
    vector<int> ans=obj.nearestHotel(arr,query);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}