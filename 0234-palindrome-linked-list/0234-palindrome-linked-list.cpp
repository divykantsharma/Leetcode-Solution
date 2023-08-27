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
 
//CAN'T use this approach as we are destroying the initial linked list - and as pehle waali destroy ho gayi toh compare kisse karenge . 
// class Solution{
// public:
//     ListNode *reverseLL(ListNode *head){
// 	   if(head==NULL || head->next==NULL) return head;
//         ListNode* newH=reverseLL(head->next);
//         ListNode* tail=head->next;
//         tail->next=head;
//         head->next=NULL;
//         return newH;
//     }
//     bool isPalindrome(ListNode* head){
//         if(head==NULL || head->next==NULL) return true;
//         ListNode* temp1=head;
//         ListNode* temp2=reverseLL(head);
//         while(temp1!=NULL){
//             cout<<temp1->val<<" ";
//             temp1=temp1->next;      
//         }      
//         cout<<endl; 
//         while(temp2!=NULL){
//             cout<<temp2->val<<" ";
//             temp2=temp2->next;      
//         }
//         while(temp1 && temp2){
//             if(temp1->val!=temp2->val) return false;
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         return true;
//     }
// };


//TC->O(N) , SC->O(1)
class Solution{
public:
    ListNode *reverseLinkedList(ListNode *head){
	   if(head==NULL || head->next==NULL) return head;
        ListNode* newH=reverseLinkedList(head->next);
        ListNode* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return newH;
    }
    bool isPalindrome(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){ //stop at last or second last node
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseLinkedList(slow->next);
        ListNode* start=head;
        ListNode* mid=slow->next;
        while(mid!=NULL){ 
            if(mid->val!=start->val) return false;
            start=start->next;
            mid=mid->next;
        }
        slow->next=reverseLinkedList(slow->next); //in order to maintain the order of LL
        return true;
    }
};


//STACK - TC->O(N) , SC->O(N)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head){
//         stack<int> st;
//         ListNode *temp=head;
//         while(temp!=NULL){
//             st.push(temp->val);
//             temp=temp->next;
//         }
//         while(head!=NULL){
//             int i=st.top();
//             st.pop();
//             if(head->val!=i) return false;
//             head=head->next;
//         }
//         return true;
//     }
// };