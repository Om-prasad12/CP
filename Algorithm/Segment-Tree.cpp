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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> input;
vector<int> segTree;

void buildTree(int low,int high,int pos){
	if(low==high){
	  segTree[pos]=input[low];
	  return;
	}
	int mid=low+(high-low)/2;
	buildTree(low,mid,2*pos+1);
	buildTree(mid+1,high,2*pos+2);
	segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
}

int rangeQuery(int qlow,int qhigh,int low,int high,int pos){
	//Total Overlap
	if(qlow<=low && qhigh>=high){
    	return segTree[pos];
	} 
    //No Overlap
	if(qlow>high || qhigh<low){
		return INT_MAX;
	}
	//Partial Overlap
	int mid=low+(high-low)/2;
	return min(rangeQuery(qlow,qhigh,low,mid,2*pos+1),rangeQuery(qlow,qhigh,mid+1,high,2*pos+2));
}


void solve() {
   int n,q;
    cin>>n>>q;
    input.resize(n);
    for(int i=0;i<n;i++) cin>>input[i];

    segTree.assign(4*n,INT_MAX);
    buildTree(0,n-1,0);

    while(q--){
        int l,r;
        cin>>l>>r; 
        cout<<rangeQuery(l,r,0,n-1,0)<<"\n";
    }
}
