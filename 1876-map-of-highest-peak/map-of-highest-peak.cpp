class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    q.push({0,{i,j}});
                    // ans[i][j]=-1;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto it=q.front();
            int h=it.first;
            int x=it.second.first;
            int y=it.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !isWater[nx][ny] && !ans[nx][ny]){
                    ans[nx][ny]=h+1;
                    q.push({h+1,{nx,ny}});
                }
            }
        }
        return ans;
    }
};