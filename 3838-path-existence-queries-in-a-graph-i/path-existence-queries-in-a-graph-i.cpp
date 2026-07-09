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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU d(n);
        for(int i=0;i<n-1;i++){
                if((nums[i+1]-nums[i])<=maxDiff && d.findPar(i)!=d.findPar(i+1)){
                    d.UnionbySize(i+1,i);
                }
        }
        vector<bool>ans;
        for(auto q:queries){
            int u=q[0];
            int v=q[1];
            if(d.findPar(u)==d.findPar(v)){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};