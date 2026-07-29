#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    set<pair<int,int>> st;
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        st.insert({arr[i],i});
	    }
	    
	    for (auto it = st.rbegin(); it != st.rend(); it++) {
            int ind=(*it).second;
            if(ind==0 | ind==n-1) continue;
            if(arr[ind+1]>arr[ind] && arr[ind-1]>arr[ind]){
                arr[ind+1]=arr[ind];
                arr[ind-1]=arr[ind];
            }
        }
        
        for(int i=0;i<n;i++) sum+=arr[i];
        
        cout<<sum<<endl;
	    
	    
	}

}