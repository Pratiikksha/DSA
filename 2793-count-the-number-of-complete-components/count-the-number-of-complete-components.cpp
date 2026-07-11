class DSU {
    vector<int> parent, rank, size;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        } else
            return parent[node] = findPar(parent[node]);
    }
    void UnionbySize(int u, int v) {
        int pv = findPar(v);
        int pu = findPar(u);
        if (pv == pu)
            return;
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        DSU d(n);
        for (auto it : edges) {
            if (d.findPar(it[0]) != d.findPar(it[1])) {
                d.UnionbySize(it[0], it[1]);
            }
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int, vector<int>> comp;
        int count=0;
        for (int i = 0; i < n; i++)
            comp[d.findPar(i)].push_back(i);
        for (auto &[p,nodes]:comp) {
            int ps =nodes.size();
            int flag = 0;
            for (int j: nodes) {
                if (adj[j].size() != ps-1) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                count += 1;
            }
        }
        return count;
    }
};