class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col,int n,int m){
        vis[row][col]=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(grid,vis,nr,nc,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    c++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return c;
    }
};