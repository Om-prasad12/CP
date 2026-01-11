#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> arr;
    string str;
    vector<char> ch={'a','b','c'};

    void solve(int n){
        if(str.size()==n){
            arr.push_back(str);
            return;
        }
        for(auto it:ch){
            if(str.empty() || str.back()!=it){
                str+=it;
                solve(n);
                if(!str.empty()) str.pop_back();
            }
        }
    }

    string getHappyString(int n,int k){
        int len=3*pow(2,n-1);
        if(k>len) return "";
        solve(n);
        return arr[k-1];
    }
};

void solve(){
    int n,k;
    cin>>n>>k;

    Solution obj;
    cout<<obj.getHappyString(n,k)<<"\n";
}

int main(){
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
