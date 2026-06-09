/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        using T = tuple<int, ListNode*>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n; i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        if (pq.empty())
            return NULL;
        auto [value, item] = pq.top();
        ListNode* head = new ListNode(value);
        ListNode* temp = new ListNode();
        temp = head;
        pq.pop();
        if (item->next) {
            pq.push({item->next->val, item->next});
        }
        while (!pq.empty()) {
            auto [value, item] = pq.top();
            if (item) {
                ListNode* temp2 = new ListNode(value);
                temp->next = temp2;
                temp = temp2;
            }
            pq.pop();
            if (item->next) {
                pq.push({item->next->val, item->next});
            }
        }
        return head;
    }
};