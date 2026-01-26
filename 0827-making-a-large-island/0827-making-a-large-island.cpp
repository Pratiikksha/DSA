class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findP(int node) {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findP(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pv = findP(v);
        int pu = findP(u);
        if (pv == pu) {
            return;
        }
        if (size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int join(int r,int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        unordered_set<int> st;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 1) {
                int nnode = nr * n + nc;
                st.insert(findP(nnode));
            }
        }
        int sum = 0;
        for (auto x : st) {
            sum += size[x];
        }
        return sum + 1;
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int dr[] = {1, 0, -1, 0};
                int dc[] = {0, 1, 0, -1};
                if(grid[i][j]==1){
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < n && nr >= 0 && nc < n && nc >= 0 &&
                        grid[nr][nc] == 1) {
                        int node = i * n + j;
                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }}
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int k = ds.join(i,j,grid);
                    maxi = max(maxi, k);
                }
            }
        }
        if(maxi==0) return n*n;
        return maxi;
    }
};