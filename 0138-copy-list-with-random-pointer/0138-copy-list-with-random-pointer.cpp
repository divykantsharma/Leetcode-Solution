/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution{
    public:
    //BRUTE FORCE - TC->O(N)+O(N) , SC->O(N)
    Node* copyRandomList(Node* head){
        map<Node*,Node*> mp;
        Node * temp=head;
        while(temp){
            Node* newnode=new Node(temp->val);  //DEEP COPY
            mp[temp]=newnode;
            temp=temp->next;
        }
        Node* newh=NULL;
        temp=head;
        for(auto it:mp){
            if(newh==NULL) newh=it.second;
            it.second->next=mp[it.first->next];
            it.second->random=mp[it.first->random];
        }
        return newh;
    }


    // unordered_map<Node*,Node*> mp;
    // Node* copyRandomList(Node* head){
    //     if(head==NULL) return NULL;
    //     if(mp.count(head)) return mp[head];
    //     Node* newNode=new Node(head->val);
    //     mp[head]=newNode;
    //     newNode->next=copyRandomList(head->next);
    //     newNode->random=copyRandomList(head->random);
    //     return newNode;
    // }
};