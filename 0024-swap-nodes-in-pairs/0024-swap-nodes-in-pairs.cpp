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
    ListNode* swapPairs(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head; 
        while(temp!=NULL && temp->next!=NULL){  //internally node change nahi kar rahe , bas value swap kar rahe hei
            int v=temp->val;
            temp->val=temp->next->val;
            temp->next->val=v;
            temp=temp->next->next;
        }
        return head;
    }
};