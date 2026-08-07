class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        vector<long long> left(N), right(N);

        // left[i] = minimum sum of n elements from nums[0...i]
        priority_queue<int> maxHeap;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
        }

        left[n - 1] = sum;

        for (int i = n; i < 2 * n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);

            sum -= maxHeap.top();
            maxHeap.pop();

            left[i] = sum;
        }

        // right[i] = maximum sum of n elements from nums[i...N-1]
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;

        for (int i = N - 1; i >= 2 * n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
        }

        right[2 * n] = sum;

        for (int i = 2 * n - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);

            sum -= minHeap.top();
            minHeap.pop();

            right[i] = sum;
        }

        long long ans = LLONG_MAX;

        for (int i = n - 1; i < 2 * n; i++) {
            ans = min(ans, left[i] - right[i + 1]);
        }

        return ans;
    }
};