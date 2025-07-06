class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& 
        waitCost) {
        using T = tuple<long long, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<vector<long long>>> dist(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));
        dist[0][0][1] = 1;
        pq.emplace(1, 1, 0, 0);
        vector<pair<int,int>> dirs = {{1,0}, {0,1}};
        while (!pq.empty()) {
            auto [cost, time, i, j] = pq.top(); pq.pop();
            int p = time % 2;
            if (dist[i][j][p] < cost) continue;
            if (i == m - 1 && j == n - 1) return cost;
            if (p == 1) {
                for (auto [dx, dy] : dirs) {
                    int ni = i + dx, nj = j + dy;
                    if (ni < m && nj < n) {
                        long long nc = cost + (ni + 1LL) * (nj + 1LL);
                        if (nc < dist[ni][nj][0]) {
                            dist[ni][nj][0] = nc;
                            pq.emplace(nc, time + 1, ni, nj);
                        }
                    }
                }
            } else {
                long long nc = cost + waitCost[i][j];
                if (nc < dist[i][j][1]) {
                    dist[i][j][1] = nc;
                    pq.emplace(nc, time + 1, i, j);
                }
            }
        }
        return -1;
    }
};
