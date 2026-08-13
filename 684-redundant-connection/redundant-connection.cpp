class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u)
            return u;
        else {
            parent[u] = findParent(parent[u]);
            return parent[u];
        }
    }
    void UnionBySize(int u, int v) {
        int pv = findParent(v);
        int pu = findParent(u);
        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);
        for (auto i : edges) {
            if (d.findParent(i[0] - 1) == d.findParent(i[1] - 1)) {
                return {i[0], i[1]};
            } else {
                d.UnionBySize(i[0] - 1, i[1] - 1);
            }
        }
        return {};
    }
};