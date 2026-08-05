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

vector<string> mp={
    "0",
    "1",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void dfs(int ind,string& str,string& temp,vector<string>& ans){
    int n=str.size();

    if(ind==n){
        ans.push_back(temp);
        return;
    }

    string x=mp[str[ind]-'0'];

    for(auto ch:x){
        temp+=ch;
        dfs(ind+1,str,temp,ans);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string str){
    vector<string> ans;
    string temp;

    dfs(0,str,temp,ans);

    return ans;
}

void solve(){
    string str;
    cin>>str;

    vector<string> ans=letterCombinations(str);

    for(auto &s:ans){
        cout<<s<<" ";
    }
    cout<<"\n";
}