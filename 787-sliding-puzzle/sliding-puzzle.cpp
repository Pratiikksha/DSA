class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start= "";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=char('0'+board[i][j]);
            }
        }
        string target="123450";
        vector<vector<int>>possibleMoves={
            {1,3}, {0,2,4},{1,5},{0,4},{1,3,5},{2,4}
        };
        queue<string>q;
        unordered_set<string>st;
        q.push(start);
        st.insert(start);
        int moves=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr==target) return moves;
                int zero=curr.find('0');
                for(auto i:possibleMoves[zero]){
                    string temp=curr;
                    swap(temp[zero],temp[i]);
                    if(!st.contains(temp)){
                        q.push(temp);
                        st.insert(temp);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};