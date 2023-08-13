/**
 * Definition for singly-linked list.
 * struct ListNode{
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* oddEvenList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp=head,*oddh=NULL,*oddt=NULL,*evenh=NULL,*event=NULL;
        int count=1;
        while(temp!=NULL){
            if(count%2==1){     //oddList
                if(oddh==NULL){
                    oddh=temp;
                    oddt=temp;
                }
                else{
                    oddt->next=temp;
                    oddt=oddt->next;
                }
            }
            else{   //evenList
                if(evenh==NULL){
                    evenh=temp;
                    event=temp;
                }
                else{
                    event->next=temp;
                    event=event->next;
                }
            }
            count++;
            temp=temp->next;
        }
        // if(oddh==NULL){      //ignore these and add base case at top - same hi baat hei 
        //     return evenh;
        // }
        // if(evenh==NULL){
        //     return oddh;
        // }
        event->next=NULL;
        oddt->next=evenh;
        return oddh;
    }


    //USING A VECTOR -  TC->O(N) , SC->O(N);
    // ListNode* oddEvenList(ListNode* head){
    //     vector<int> store; 
    //     ListNode* temp=head;
    //     while(temp!=NULL){
    //         store.push_back(temp->val);
    //         temp=temp->next;
    //     }
    //     vector<int> major;
    //     for(int i=0;i<store.size();i++){
    //         if(i%2==0){
    //             major.push_back(store[i]);
    //             cout<<store[i]<<" ";
    //         }
    //     }
    //     for(int i=0;i<store.size();i++){
    //         if(i%2!=0){
    //             major.push_back(store[i]);
    //             cout<<store[i]<<" ";
    //         }
    //     }
    //     temp=head;
    //     int i=0;
    //     while(temp!=NULL){  //over writing on the initial linked list
    //         temp->val=major[i++];
    //         temp=temp->next;
    //     }
    //     return head;
    // }
};