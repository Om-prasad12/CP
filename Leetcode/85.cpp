#include<bits/stdc++.h>
using namespace std;

int hMax(int arr[],int m){
    stack<int> st;
    int maxArea=0;

    for(int i=0;i<m;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int ele=arr[st.top()];
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,ele*(nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()){
        int ele=arr[st.top()];
        st.pop();
        int nse=m;
        int pse=st.empty()?-1:st.top();
        maxArea=max(maxArea,ele*(nse-pse-1));
    }

    return maxArea;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> matrix(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    int pSum[n][m];
    int maxArea=0;

    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            if(matrix[i][j]=='1') sum++;
            else sum=0;
            pSum[i][j]=sum;
        }
    }

    for(int i=0;i<n;i++){
        maxArea=max(maxArea,hMax(pSum[i],m));
    }

    cout<<maxArea<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}
