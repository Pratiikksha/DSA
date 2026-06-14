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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=new ListNode(0);
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(!fast->next){
            prev->next=slow->next;
        }
        else{
            prev=slow;
            prev->next=slow->next->next;
        }
        return head;
    }
};