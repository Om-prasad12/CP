class Solution {
public:
    long long maxArea(vector<vector<int>>& nums) {
        int n = nums.size();
        int xmin = INT_MAX, xmax = INT_MIN;
        int ymin = INT_MAX, ymax = INT_MIN;
        map<int, vector<int>> xmpp, ympp;

        for (int i = 0; i < n; i++) {
            int x = nums[i][0];
            int y = nums[i][1];
            xmpp[x].push_back(y);
            ympp[y].push_back(x);
            xmin = min(xmin, x);
            xmax = max(xmax, x);
            ymin = min(ymin, y);
            ymax = max(ymax, y);
        }

        long long ans = -1;

        for (auto it : xmpp) {
            if (it.second.size() < 2) continue;
            vector<int>& v = it.second;
            int minY = *min_element(v.begin(), v.end());
            int maxY = *max_element(v.begin(), v.end());
            long long height = 1LL * maxY - minY;
            long long dist = max(1LL * abs(xmin - it.first), 1LL *             abs(xmax - it.first));
            long long area = height * dist;
            ans = max(ans, area);
        }

        for (auto it : ympp) {
            if (it.second.size() < 2) continue;
            vector<int>& v = it.second;
            int minX = *min_element(v.begin(), v.end());
            int maxX = *max_element(v.begin(), v.end());
            long long height = 1LL * maxX - minX;
            long long dist = max(1LL * abs(ymin - it.first), 1LL *             abs(ymax - it.first));
            long long area = height * dist;
            ans = max(ans, area);
        }

        if (ans == 0) return -1;
        return ans;
    }
};
