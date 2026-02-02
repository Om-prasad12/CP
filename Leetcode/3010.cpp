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
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int smallest=INT_MAX,second_smallest=INT_MAX;

        for (int i=1;i<n;i++)
        {
            if (nums[i]<smallest)
            {
                second_smallest=smallest;
                smallest=nums[i];
                continue;
            }
            if (nums[i]<second_smallest)
                second_smallest=nums[i];
        }

        return nums[0]+smallest+second_smallest;
    }
};
//PLEASE UPVOTE IF IT HELPS 😁

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    Solution obj;
    cout<<obj.minimumCost(nums)<<"\n";
}
