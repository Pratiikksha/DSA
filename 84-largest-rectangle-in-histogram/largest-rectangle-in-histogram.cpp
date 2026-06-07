class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        heights.push_back(0);
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int nse=i;
                int k=heights[st.top()];
                st.pop();
                int pse;
                if(st.empty())  pse=-1;
                else pse=st.top();
                int area=k*(nse-pse-1);
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        return maxi;

    }
};