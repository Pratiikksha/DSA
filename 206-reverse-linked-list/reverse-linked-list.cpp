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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* temp=nullptr;
        while(curr->next){
            ListNode* temp2=curr->next;
            curr->next=temp;
            temp=curr;
            curr=temp2;
        }
        curr->next=temp;
        return curr;
    }
};