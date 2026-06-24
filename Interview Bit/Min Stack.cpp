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

class MinStack {
public:
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

stack<int> st,mn;

MinStack::MinStack() {
    while(!st.empty()) st.pop();
    while(!mn.empty()) mn.pop();
}

void MinStack::push(int x) {
    st.push(x);

    if(mn.empty())
        mn.push(x);
    else
        mn.push(min(x,mn.top()));
}

void MinStack::pop() {
    if(st.empty()) return;
    st.pop();
    mn.pop();
}

int MinStack::top() {
    if(st.empty()) return -1;
    return st.top();
}

int MinStack::getMin() {
    if(st.empty()) return -1;
    return mn.top();
}

void solve() {
    int q;
    cin>>q;

    MinStack obj;

    while(q--){
        string op;
        cin>>op;

        if(op=="push"){
            int x;
            cin>>x;
            obj.push(x);
        }
        else if(op=="pop"){
            obj.pop();
        }
        else if(op=="top"){
            cout<<obj.top()<<"\n";
        }
        else if(op=="getMin"){
            cout<<obj.getMin()<<"\n";
        }
    }
}