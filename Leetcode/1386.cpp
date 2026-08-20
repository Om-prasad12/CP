#include<bits/stdc++.h>
using namespace std;
void solve();

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
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

bool check(vector<bool>& reserved,int l,int r){
    for(int i=l;i<=r;i++){
        if(reserved[i])
            return false;
    }
    return true;
}

int maxNumberOfFamilies(int n,vector<vector<int>>& reservedSeats){
    sort(reservedSeats.begin(),reservedSeats.end());

    int m=reservedSeats.size();
    int ans=0;

    vector<bool> reserved(11,false);

    int l=0,r=0;
    int prev=0;

    while(r<m){
        ans+=2*(reservedSeats[r][0]-prev-1);

        prev=reservedSeats[r][0];

        while(r<m && reservedSeats[r][0]==reservedSeats[l][0]){
            reserved[reservedSeats[r][1]]=true;
            r++;
        }

        bool twoToFive=check(reserved,2,5);
        bool fourToSeven=check(reserved,4,7);
        bool sixToNine=check(reserved,6,9);

        if(twoToFive && sixToNine)
            ans+=2;
        else if(twoToFive || fourToSeven || sixToNine)
            ans++;

        l=r;

        fill(reserved.begin(),reserved.end(),false);
    }

    ans+=2*(n-prev);

    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> reservedSeats(m,vector<int>(2));

    for(int i=0;i<m;i++)
        cin>>reservedSeats[i][0]>>reservedSeats[i][1];

    cout<<maxNumberOfFamilies(n,reservedSeats)<<"\n";
}