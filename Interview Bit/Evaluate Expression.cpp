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
    int evalRPN(vector<string> &arr) {
        stack<int> st;

        for (string s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};

void solve() {
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    cout<<obj.evalRPN(arr)<<"\n";
}