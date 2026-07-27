class Solution {
public:
    int row;
    int col;
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[x][y]=1;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<row && nx>=0 && ny<col && ny>=0 && grid[nx][ny]=='1' && !vis[nx][ny]){
                dfs(nx,ny,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        row=m;
        col=n;
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};