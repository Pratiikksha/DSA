class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        // Step 1: Count nodes
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }

        // Step 2: Calculate sizes
        int base = n / k;
        int extra = n % k;

        curr = head;

        // Step 3: Split
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int partSize = base + (i < extra ? 1 : 0);

            // Move to end of this part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // Cut the list
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }

        return result;
    }
};
