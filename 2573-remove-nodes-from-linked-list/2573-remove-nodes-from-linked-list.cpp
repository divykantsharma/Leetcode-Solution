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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* newh=reverseLL(head);
        ListNode* temp=newh; 
        // while(temp!=NULL){       //for checking purpose
        //      cout<<temp->val<<" ";
        //      temp=temp->next;
        // }
        // temp=newh;
        while(temp && temp->next){
            if(temp->next->val<temp->val){
                temp->next=temp->next->next;
            }
            else temp=temp->next;
        }
        return reverseLL(newh);
    }
};