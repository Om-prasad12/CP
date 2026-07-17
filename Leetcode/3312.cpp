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
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> frequency(maxValue + 1);
        for(int value : nums){
            frequency[value]++;
        }

        vector<int> divisibleCount(maxValue + 1);
        for(int gcd = 1; gcd <= maxValue; gcd++){
            for(int multiple = gcd; multiple <= maxValue; multiple += gcd){
                divisibleCount[gcd] += frequency[multiple];
            }
        }

        vector<long long> gcdPairCount(maxValue + 1);
        for(int gcd = maxValue; gcd >= 1; gcd--){
            long long count = divisibleCount[gcd];
            gcdPairCount[gcd] = count * (count - 1) / 2;

            for(int multiple = gcd * 2; multiple <= maxValue; multiple += gcd){
                gcdPairCount[gcd] -= gcdPairCount[multiple];
            }
        }

        vector<long long> prefix(maxValue + 1);
        for(int gcd = 1; gcd <= maxValue; gcd++){
            prefix[gcd] = prefix[gcd - 1] + gcdPairCount[gcd];
        }

        vector<int> answer;

        for(long long query : queries){
            int left = 1;
            int right = maxValue;

            while(left < right){
                int mid = left + (right - left) / 2;
                if(prefix[mid] > query)
                    right = mid;
                else
                    left = mid + 1;
            }

            answer.push_back(left);
        }

        return answer;
    }
};

void solve() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    int q;
    cin>>q;

    vector<long long> queries(q);
    for(int i=0;i<q;i++) cin>>queries[i];

    Solution obj;
    vector<int> ans = obj.gcdValues(nums, queries);

    for(int x : ans) cout<<x<<" ";
    cout<<"\n";
}