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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* finalhead=NULL;
        ListNode* finaltail=NULL;
        if(list1->val<list2->val){
            finalhead=list1;
            finaltail=list1;
            list1=list1->next;
        }
        else{
            finalhead=list2;
            finaltail=list2;
            list2=list2->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                finaltail->next=list1;
                finaltail=list1;
                list1=list1->next;
            }
            else{
                finaltail->next=list2;
                finaltail=list2;
                list2=list2->next;
            }
        }
        while(list1!=NULL && list2==NULL){
            finaltail->next=list1;
            finaltail=list1;
            list1=list1->next;
        }
        while(list1==NULL && list2!=NULL){
            finaltail->next=list2;
            finaltail=list2;
    	    list2=list2->next;
	    }
    return finalhead;
    }
};