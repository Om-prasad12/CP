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

class Solution {
public:
    void operation(vector<string>& arr, vector<string>& ans, string& temp, int ind){
        if(ind==arr.size()){
            ans.push_back(temp);
            return;
        }

        for(auto ch:arr[ind]){
            temp+=ch;
            operation(arr,ans,temp,ind+1);
            temp.pop_back();
        }
    }

    vector<string> specialStrings(vector<string> &arr) {
        int n=arr.size();

        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
        }

        vector<string> ans;
        string temp="";
        operation(arr,ans,temp,0);

        return ans;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj;
    vector<string> ans=obj.specialStrings(arr);

    for(auto &s:ans) cout<<s<<"\n";
}