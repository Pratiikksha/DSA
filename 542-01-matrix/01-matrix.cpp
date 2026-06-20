class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                    k++;
                }
            }
        }
         k=(n*m)-k;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[r][c]+1;
                    k--;
                    if(k==0) return dist;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};