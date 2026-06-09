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
        ListNode* head = new ListNode();
        ListNode* temp = new ListNode();
        ListNode* temp3 = new ListNode();
        temp3 = item->next;
        item->next = nullptr;
        head = item;
        temp = head;
        pq.pop();
        if (temp3) {
            pq.push({temp3->val, temp3});
        }
        while (!pq.empty()) {
            auto [value, item] = pq.top();
            ListNode* temp2 = new ListNode();
            temp2 = item->next;
            if (item) {
                item->next = nullptr;
                temp->next= item;
                temp=item;
            }
            pq.pop();
            if (temp2) {
                pq.push({temp2->val, temp2});
            }
        }
        return head;
    }
};