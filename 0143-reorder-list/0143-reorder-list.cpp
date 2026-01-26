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
    void reorderList(ListNode* head) {
        ListNode* temp1=head;
        while(temp1->next!=NULL && temp1->next->next!=NULL){
            ListNode* j=temp1;
            ListNode* temp3;
            while(j->next!=NULL){
               temp3=j;
               j=j->next;
            }
            ListNode* temp4=temp1->next;
            temp1->next=j;
            j->next=temp4;
            temp3->next=NULL;
            temp1=j->next;
        }
    }
};