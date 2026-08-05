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

bool checkPalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void dfs(string& str,vector<string>& temp,vector<vector<string>>& ans,int ind){
    int n=str.size();

    if(ind==n){
        ans.push_back(temp);
        return;
    }

    for(int i=ind;i<n;i++){
        if(checkPalindrome(str,ind,i)){
            temp.push_back(str.substr(ind,i-ind+1));
            dfs(str,temp,ans,i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string str){
    vector<vector<string>> ans;
    vector<string> temp;

    dfs(str,temp,ans,0);

    return ans;
}

void solve(){
    string str;
    cin>>str;

    vector<vector<string>> ans=partition(str);

    for(auto &v:ans){
        for(auto &s:v){
            cout<<s<<" ";
        }
        cout<<"\n";
    }
}