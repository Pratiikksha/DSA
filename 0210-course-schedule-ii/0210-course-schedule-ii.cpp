class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj, vector<int>&vis,vector<int>& path,stack<int>& st){
        vis[node]=1;
        path[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,adj,vis,path,st))
                return true;
            }
            else if(path[adjNode]){
                return true;
            }
        }
        st.push(node);
        path[node]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int> st;
        vector<int>vis(numCourses,0),path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,vis,path,st);
            }
        }
        if(st.size()!=numCourses)return{};
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};