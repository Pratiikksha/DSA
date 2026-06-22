class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for (int i = 0; i < prerequisites.size();i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        if (q.empty())
            return {};
        vector<int> ans;
        vector<int> visited(numCourses, 0);
        while (!q.empty()) {
            int curr = q.front();
            ans.push_back(curr);
            visited[curr]=1;
            q.pop();
            for (int nei : adj[curr]) {
                if (!visited[nei]) {
                    inDegree[nei]--;
                    if (inDegree[nei] == 0)
                        q.push(nei);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};