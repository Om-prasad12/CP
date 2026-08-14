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

int maximumXOR(vector<int>& A,vector<int>& B){
    struct Node{
        Node* child[2];

        Node(){
            child[0]=NULL;
            child[1]=NULL;
        }
    };

    Node* root=new Node();

    for(int num:B){
        Node* curr=root;

        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;

            if(curr->child[bit]==NULL)
                curr->child[bit]=new Node();

            curr=curr->child[bit];
        }
    }

    int ans=0;

    for(int num:A){
        Node* curr=root;
        int currXor=0;

        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;
            int opposite=1-bit;

            if(curr->child[opposite]!=NULL){
                currXor|=(1<<i);
                curr=curr->child[opposite];
            }
            else{
                curr=curr->child[bit];
            }
        }

        ans=max(ans,currXor);
    }

    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> A(n),B(m);

    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<m;i++)
        cin>>B[i];

    cout<<maximumXOR(A,B)<<"\n";
}