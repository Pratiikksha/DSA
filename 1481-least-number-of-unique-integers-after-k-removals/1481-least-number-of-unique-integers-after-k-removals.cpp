class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        // Step 1: count frequency
        for (int x : arr) {
            freq[x]++;
        }

        // Step 2: store frequencies
        vector<int> counts;
        for (auto &p : freq) {
            counts.push_back(p.second);
        }

        // Step 3: sort frequencies
        sort(counts.begin(), counts.end());

        // Step 4: greedily remove
        int unique = counts.size();

        for (int c : counts) {
            if (k >= c) {
                k -= c;
                unique--;
            } else {
                break;
            }
        }

        return unique;
    }
};