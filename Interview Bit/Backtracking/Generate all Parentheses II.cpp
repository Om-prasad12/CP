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

void dfs(int x,int y,string& temp,vector<string>& ans){
    if(x==0 && y==0){
        ans.push_back(temp);
        return;
    }

    if(x>0 && x>=y){
        temp+='(';
        dfs(x-1,y,temp,ans);
        temp.pop_back();
    }
    else{
        temp+='(';
        if(x>0) dfs(x-1,y,temp,ans);
        temp.pop_back();

        temp+=')';
        if(y>0) dfs(x,y-1,temp,ans);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    string temp;

    dfs(n,n,temp,ans);

    return ans;
}

void solve(){
    int n;
    cin>>n;

    vector<string> ans=generateParenthesis(n);

    for(auto &s:ans){
        cout<<s<<"\n";
    }
}