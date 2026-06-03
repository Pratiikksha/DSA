class Solution {
    int solve(vector<int>& start1,
              vector<int>& dur1,
              vector<int>& start2,
              vector<int>& dur2) {

        int minFinish = INT_MAX;

        for (int i = 0; i < start1.size(); i++)
            minFinish = min(minFinish, start1[i] + dur1[i]);

        int ans = INT_MAX;

        for (int i = 0; i < start2.size(); i++)
            ans = min(ans,
                      max(start2[i], minFinish) + dur2[i]);

        return ans;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),

            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );
    }
};