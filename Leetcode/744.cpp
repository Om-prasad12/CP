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
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() -1;
        char ans = letters[0];
        while(l<=r){
            int mid = (l+r)/2;
            char c = letters[mid];
            if(c > target){
                ans = c;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<char> letters(n);
    for(int i=0;i<n;i++) cin>>letters[i];
    char target;
    cin>>target;

    Solution obj;
    cout<<obj.nextGreatestLetter(letters,target)<<"\n";
}
