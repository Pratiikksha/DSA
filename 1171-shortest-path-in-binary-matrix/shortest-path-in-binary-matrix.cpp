class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1)
            return -1;
        q.push({1, {0, 0}});
        int dx[8]={0,1,-1,0,-1,1,1,-1};
        int dy[8]={-1,0,0,1,1,1,-1,-1};
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while (!q.empty()) {
            auto it = q.front();
            int x=it.second.first;
            int y=it.second.second;
            int d=it.first;
            q.pop();
            if(x==n-1 && y==n-1) return d;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && nx>=0 && ny<n && ny>=0 && !grid[nx][ny] && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        return -1;

    }
};