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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> minh; //min heap to mantain the smallest element at the top 
        for(int i=0;i<lists.size();i++){         // for loop to insert all elements into the linked list
            ListNode* head=lists[i];
            while(head!=NULL){
                minh.push(head->val);
                head=head->next;
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(minh.size()>0){      //taking elements from min heap and making linked list using head tail method
            int rootdata=minh.top();
            ListNode* newnode=new ListNode(rootdata);
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=newnode;
            }
            minh.pop();
        }
        return head;
    }
};