class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        set<int> s;

        auto add_toset = [&](int num){
            s.insert(num);

            if(s.size() > 3){
                s.erase(s.begin());
            }
        };

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                add_toset(grid[i][j]);

                int side = 1;

                while(i - side >= 0 && i + side < m && j - side >= 0 && j+side < n){
                    int sum = 0;

                    for(int k = 0 ; k < side ; k++){
                        sum += grid[i-side+k][j+k];
                        sum += grid[i+side-k][j-k];
                        sum += grid[i-k][j-side+k];
                        sum += grid[i+k][j+side-k];
                    }
                    add_toset(sum);
                    side++;
                }
            }
        }
        return vector<int>(s.rbegin() , s.rend());
    }
};