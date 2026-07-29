#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    if(z<=y){
	        cout<<-1<<endl;
	    } else{
	        cout<<ceil((double)x/(z-y))<<endl;
	    }
	}
	
}