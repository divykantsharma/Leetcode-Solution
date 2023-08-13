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
class Solution{
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newH=reverseLL(head->next);
        ListNode* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return newH;
    }
    ListNode* doubleIt(ListNode* head){
        ListNode* temp1=reverseLL(head);
        ListNode* dummy=new ListNode(0);
        ListNode* temp2=dummy;
        int carry=0;
        while(temp1 || carry){
            int sum=0;
            if(temp1){
                sum+=(temp1->val)*2;
                temp1=temp1->next;  
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp2->next=newnode;
            temp2=temp2->next;
        }
        return reverseLL(dummy->next);
    }
};