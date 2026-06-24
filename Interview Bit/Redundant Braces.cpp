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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

class Solution {
public:
    int braces(string str) {
        int n=str.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(str[i]==')'){
                bool state=false;
                while(st.top()!='('){
                    char x=st.top();
                    if(x=='+' || x=='-' || x=='*' || x=='/') state=true;
                    st.pop();
                }
                if(state==false) return 1;
                st.pop();
            } else{
                st.push(str[i]);
            }
        }
        return 0;
    }
};

void solve() {
    string str;
    cin>>str;

    Solution obj;
    cout<<obj.braces(str)<<"\n";
}