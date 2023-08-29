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
    //USING MERGE SORT - TC -> O(NlogN) , SC -> O(1)
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp=NULL;    //keeps track of node which is end of our first half
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast != NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;          
            fast=fast->next->next;  
        }   
        temp->next=NULL;            
        ListNode* l1 = sortList(head);  //2   
        ListNode* l2 = sortList(slow);  //1 
        return mergelist(l1, l2);         
    }
    ListNode* mergelist(ListNode *head1,ListNode *head2){   //merge 2 sorted LL
        ListNode *fh=NULL,*ft=NULL;
        while(head1!=NULL && head2!=NULL){
            if(fh==NULL && ft==NULL){
                if(head1->val>head2->val){
                    fh=head2;
                    ft=head2;
                    head2=head2->next;
                }else{
                    fh=head1;
                    ft=head1;
                    head1=head1->next;
                }
            }
            if(head1 && head2){
                if(head1->val<head2->val){
                    ft->next=head1;
                    ft=ft->next;
                    head1=head1->next;

                }
                else{
                    ft->next=head2;
                    ft=ft->next;
                    head2=head2->next;
                }
            }
        }
        if(head1!=NULL && head2==NULL){
            ft->next=head1;
            head1=head1->next;
        }
        if(head1==NULL && head2!=NULL){
            ft->next=head2;
            head2=head2->next;
        }
        return fh;
    }
}; 


//USING PRIORITY QUEUE - MIN HEAP - TC -> O(NlogN) , SC -> O(N)
// class Solution {
// public:
//     ListNode* sortList(ListNode* head){
//         if(head==NULL || head->next==NULL) return head;
//         priority_queue<int, vector<int>, greater<int>> pq;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             pq.push(temp->val);
//             temp=temp->next;
//         }
//         temp=head;
//         while(pq.size()!=0 && temp!=NULL){
//             int data=pq.top();  //destroying the given linked list
//             pq.pop();
//             temp->val=data;
//             temp=temp->next;
//         }
//         return head;
//     }
// };