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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=reverseLL(head->next);
        ListNode* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return temp;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseLL(slow->next);
        ListNode* temp1=head;
        ListNode* temp2=slow->next;
        int maxi=INT_MIN;
        while(temp2!=NULL){
            int sum=temp1->val+temp2->val;
            maxi=max(maxi,sum);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        slow->next=reverseLL(slow->next);
        return maxi;
    }
};