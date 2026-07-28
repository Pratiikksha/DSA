class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int row;
    int col;
    bool dfs(int x, int y,int px, int py, char c, vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx==px && ny==py) continue;
            if(nx<row && ny<col && nx>=0 && ny>=0 && grid[nx][ny]==c){
                if(vis[nx][ny]){
                    return true;
                }
                else {
                    if(dfs(nx,ny,x,y,c,grid,vis))
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int  m=grid.size();
        int n=grid[0].size();
        row=m;
        col=n;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid[i][j],grid,vis))
                    return true;
                }
            }
        }
        return false;
    }
};