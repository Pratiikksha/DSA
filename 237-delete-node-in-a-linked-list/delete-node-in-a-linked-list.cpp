/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev=node;
        while(node->next){
            node=node->next;
            prev->val=node->val;
            if(node->next)
            prev=node;
        }
        prev->next=nullptr;
    }
};