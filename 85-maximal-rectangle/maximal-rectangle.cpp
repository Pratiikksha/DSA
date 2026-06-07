class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int nse = i;
                int k = heights[st.top()];
                st.pop();
                int pse;
                if (st.empty())
                    pse = -1;
                else
                    pse = st.top();
                int area = k * (nse - pse - 1);
                maxi = max(maxi, area);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> histogram(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            histogram[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                histogram[i][j]=histogram[i-1][j]+matrix[i][j]-'0';
            }
        }
        int maximum=0;
        for(int i=0;i<n;i++){
            int area=largestRectangleArea(histogram[i]);
            maximum=max(maximum,area);
        }
        return maximum;

    }
};