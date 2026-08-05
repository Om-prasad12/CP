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

vector<int> remainingMethods(int n,int k,vector<vector<int>>& invocations){
    vector<vector<int>> adj(n);

    for(int i=0;i<invocations.size();i++){
        adj[invocations[i][0]].push_back(invocations[i][1]);
    }

    vector<int> vis(n,0);
    queue<int> q;
    set<int> st;

    q.push(k);
    st.insert(k);
    vis[k]=1;

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        for(int i=0;i<adj[temp].size();i++){
            int x=adj[temp][i];
            st.insert(x);

            if(vis[x]==0){
                q.push(x);
                vis[x]=1;
            }
        }
    }

    bool status=true;

    for(int i=0;i<n;i++){
        if(st.find(i)==st.end()){
            for(int j=0;j<adj[i].size();j++){
                if(st.find(adj[i][j])!=st.end()){
                    status=false;
                    break;
                }
            }
        }
    }

    vector<int> ans;

    for(int i=0;i<n;i++){
        if(status && st.find(i)!=st.end()) continue;
        ans.push_back(i);
    }

    return ans;
}

void solve(){
    int n,k,m;
    cin>>n>>k>>m;

    vector<vector<int>> invocations(m,vector<int>(2));

    for(int i=0;i<m;i++){
        cin>>invocations[i][0]>>invocations[i][1];
    }

    vector<int> ans=remainingMethods(n,k,invocations);

    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}