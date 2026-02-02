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
    long long Sum=0;
    multiset<int> small, large;

    void add(int x, int m) {
        small.insert(x);
        Sum+=x;
        if (small.size()>m) {
            int toMove=*small.rbegin();
            Sum-=toMove;
            large.insert(toMove);
            small.erase(prev(small.end()));
        }
    }

    void remove(int x) {
        auto it=small.find(x);
        if (it!=small.end()) {
            Sum-=x;
            small.erase(it);
            if (!large.empty()) {
                auto lit=large.begin();
                int toMove=*lit;
                Sum+=toMove;
                small.insert(toMove);
                large.erase(lit);
            }
        } 
        else {
            auto itL=large.find(x);
            large.erase(itL);
        }
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int n=nums.size();
        k--;

        const int iN=dist+2;
        vector<int> win(nums.begin()+1, nums.begin()+iN);
    
        nth_element(win.begin(), win.begin()+k, win.end());
        small=multiset<int>(win.begin(), win.begin()+k);
        Sum=accumulate(win.begin(), win.begin()+k, 0LL);
        large=multiset<int>(win.begin()+k, win.end());
    
        long long minCost=nums[0]+Sum;

        for (int l=1, r=dist+2; r<n; l++, r++) {
            remove(nums[l]);
            add(nums[r], k);
            minCost=min(minCost, nums[0]+Sum);
        }
        return minCost;
    }
};

void solve() {
    int n,k,dist;
    cin>>n>>k>>dist;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<obj.minimumCost(nums,k,dist)<<"\n";
}
