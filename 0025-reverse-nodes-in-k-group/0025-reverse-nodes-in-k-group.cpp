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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp=head->next;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
           curr=temp->next;
           temp->next=prev;
           prev=temp;
           temp=curr;
        }
        head->next=nullptr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        ListNode dummy(0);
        ListNode* newList=&dummy;
        while(temp){
            int cnt=0;
            ListNode* curr=temp;
            for(int i=0;i<k-1;i++){
                if(temp->next){
                temp=temp->next;
                cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt==k-1){
                ListNode* after=temp->next;
                temp->next=nullptr;
                ListNode* reversed=reverse(curr);
                newList->next=reversed;
                newList=curr;
                temp=after;
            }
            else{
                newList->next=curr;
                break;
            }
        }
        return dummy.next;
    }
};