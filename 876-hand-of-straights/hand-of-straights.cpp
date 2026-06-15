class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        if(groupSize==1) return true;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : hand) {
            pq.push(i);
        }
        int last = pq.top();
        pq.pop();
        vector<int> saved;
        int cnt = 1;
        while (!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            if (curr == last) {
                saved.push_back(curr);
            } else if (curr == last + 1) {
                cnt++;
                last = curr;
                if (cnt == groupSize) {
                    if (pq.empty() && saved.size()==0) {
                        return true;
                    }
                    for (int i : saved) {
                        pq.push(i);
                    }
                    saved.clear();
                    last = pq.top();
                    cnt = 1;
                    pq.pop();
                }
            } else
                return false;
        }
        return false;
    }
};