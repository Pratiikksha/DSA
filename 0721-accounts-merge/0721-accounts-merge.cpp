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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else
                    ds.UnionbySize(mp[accounts[i][j]], i);
            }
        }
        vector<vector<string>> mpp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                int k = ds.findPar(mp[accounts[i][j]]);
                mpp[k].push_back(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mpp[i].size() == 0)
                continue;
            sort(mpp[i].begin(), mpp[i].end());
            mpp[i].erase(unique(mpp[i].begin(), mpp[i].end()), mpp[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mpp[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};