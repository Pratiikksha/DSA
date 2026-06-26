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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int k = connections.size();
        int t = 0;
        int x = 0;
        for (int i = 0; i < k; i++) {
            int p1 = ds.findPar(connections[i][0]);
            int p2 = ds.findPar(connections[i][1]);
            if (p1 == p2)
                t++;
            else {
                ds.UnionBySize(connections[i][0], connections[i][1]);
                x++;
            }
        }
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findPar(i) == i)
                components++;
        }
        if (t >= components - 1)
            return components - 1;
        else
            return -1;
    }
};