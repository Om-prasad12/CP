class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        UnionFind(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (x != parent[x])
                parent[x] = find(parent[x]);
            return parent[x];
        }
        bool unite(int x, int y) {
            int xr = find(x), yr = find(y);
            if (xr == yr) return false;
            parent[xr] = yr;
            return true;
        }
    };

    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),[](const vector<int>& a,const vector<int>& b) 
        {
            return a[2]<b[2];
        });
        UnionFind uf(n);
        vector<int> mstEdges;
        for (const auto& edge:edges) {
            if (uf.unite(edge[0],edge[1])) {
                mstEdges.push_back(edge[2]);
            }
        }
        sort(mstEdges.begin(), mstEdges.end(), greater<int>());
        int components = 1;
        while (components < k && !mstEdges.empty()) {
            mstEdges.erase(mstEdges.begin());
            components++;
        }
        return mstEdges.empty() ? 0 : mstEdges[0];
    }
};
