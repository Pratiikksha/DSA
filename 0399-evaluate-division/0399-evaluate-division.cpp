class Solution {
public:
    bool dfs(int u, int v, vector<vector<pair<int,double>>> &adj,
             vector<int> &vis, double &res, double curr) {
        if (u == v) {
            res = curr;
            return true;
        }
        vis[u] = 1;

        for (auto &node : adj[u]) {
            int nxt = node.first;
            double wt = node.second;
            if (!vis[nxt]) {
                if (dfs(nxt, v, adj, vis, res, curr * wt))
                    return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, int> mp;
        int id = 0;

        for (auto &e : equations) {
            if (!mp.count(e[0])) mp[e[0]] = id++;
            if (!mp.count(e[1])) mp[e[1]] = id++;
        }

        vector<vector<pair<int,double>>> adj(id);
        for (int i = 0; i < equations.size(); i++) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> ans;
        for (auto &q : queries) {
            if (!mp.count(q[0]) || !mp.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }

            int u = mp[q[0]];
            int v = mp[q[1]];
            vector<int> vis(id, 0);
            double res = -1.0;

            dfs(u, v, adj, vis, res, 1.0);
            ans.push_back(res);
        }
        return ans;
    }
};
