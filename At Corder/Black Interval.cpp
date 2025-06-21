#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> box(n, 0);
    vector<int> que(q);
    for (int i = 0; i < q; i++) cin >> que[i];

    int black = 0;

    for (int i = 0; i < q; i++) {
        int ind = que[i] - 1; 

        if (box[ind] == 1) {
        	if((ind!=0 && box[ind-1]==1) && (ind!=n-1 && box[ind+1]==1)){
                black++;
        	} else if ((ind == 0 || box[ind - 1] != 1) && (ind == n - 1 || box[ind + 1] != 1)) {
                black--;  
            }
        }
        box[ind] ^= 1;

        
        if (box[ind] == 1) {
        	if((ind!=0 && box[ind-1]==1) && (ind!=n-1 && box[ind+1]==1)){
        		black--;
        	} else if ((ind == 0 || box[ind - 1] != 1) && (ind == n - 1 || box[ind + 1] != 1)) {
                black++;  // one new black interval added
            }
        }

        cout << black << '\n';
    }
}
