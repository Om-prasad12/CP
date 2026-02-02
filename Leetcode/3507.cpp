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
    int minPair(vector<int> v){
        int minSum = 1e9;
        int pos = -1;
        for(int i = 0; i < (int)v.size() - 1; i ++){
            if(v[i] + v[i + 1] < minSum){
                minSum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }
    void mergePair(vector<int> &v, int pos){
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(nums.begin(), nums.end())){
            mergePair(nums, minPair(nums));
            ops += 1;
        }
        return ops;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<obj.minimumPairRemoval(nums)<<"\n";
}
