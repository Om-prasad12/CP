#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int operation(int x,int y,char ch){
        if(ch=='+'){
            return x+y;
        } else if(ch=='-'){
            return x-y;
        } 
        return x*y;
    }

    vector<int> solve(string str,int start,int end){
        if(end-start<=1){
            int num=stoi(str.substr(start, end - start + 1));
            return {num};
        }
        vector<int> ans;
        for(int i=start;i<=end;i++){
            if(str[i]=='+' || str[i]=='-' || str[i]=='*'){
                vector<int> left=solve(str,start,i-1);
                vector<int> right=solve(str,i+1,end);
                for(int j=0;j<left.size();j++){
                    for(int l=0;l<right.size();l++){
                        ans.push_back(operation(left[j],right[l],str[i]));
                    }
                }
            }
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string str) {
        int n=str.size();
        return solve(str,0,n-1);
    }
};

void solve(){
    string str;
    cin>>str;

    Solution ob;
    vector<int> res = ob.diffWaysToCompute(str);

    for(int x:res){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    int t=1;
    // cin>>t;
    while(t--) solve();

    cerr<<"time: "<<(float)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
