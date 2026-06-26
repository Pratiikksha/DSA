class DSU {
    vector<int> size, parent;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void UnionBySize(int u, int v) {
        int pv = findPar(v);
        int pu = findPar(u);
        if (pv == pu)
            return;
        else if (size[pv] > size[pu]) {
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j)
                    continue;
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    ds.UnionBySize(i, j);
                }
            }
        }
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
            st.insert(ds.findPar(i));

        return n - st.size();
    }
};