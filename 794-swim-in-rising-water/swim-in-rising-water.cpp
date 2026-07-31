class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0],{0,0}});
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int h=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1 && y==n-1) return h;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 || ny<0 ||  nx>=n || ny>=n) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny]=1;
                pq.push({max(h,grid[nx][ny]),{nx,ny}});
            }
        }
        return -1;
    }
};