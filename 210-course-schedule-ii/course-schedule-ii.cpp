class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        queue<int>q;
        int vis=0;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        if(q.empty()) return{};
        vector<int>ans;
        while(!q.empty()){
            int sub=q.front();
            ans.push_back(sub);
            vis++;
            q.pop();
            for(int i:adj[sub]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(vis!=numCourses) return {};
        return ans;
    }
};