class Solution {
public:
    int countSwaps(queue<int> q, int start) {
        int swaps = 0;
        while (!q.empty()) {
            int currIndex = q.front();
            q.pop();
            swaps += abs(currIndex -start);
            start += 2;
        }
        return swaps;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;
        queue<int> evenPos, oddPos;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                even++;
                evenPos.push(i);
            } else {
                odd++;
                oddPos.push(i);
            }
        }
        if (abs(even - odd) > 1) return -1;
        int ans= INT_MAX;
        if (even >=odd) {
            queue<int> temp = evenPos;
            int swaps = countSwaps(temp, 0);
            ans= min(ans,swaps);
        }
        if (odd >= even) {
            queue<int> temp = oddPos;
            int swaps = countSwaps(temp, 0);
            ans= min(ans, swaps);
        }

        return ans;
    }
};
