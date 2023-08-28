class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class MyLinkedList{
public:
    Node* head; 
    Node* tail;
    MyLinkedList(){
        head=NULL;
        tail=NULL;
    }
    
    int get(int index){
        if(head==NULL) return -1;
        if(index==0) return head->data;
        Node* temp=head;
        int i=0;
        while(temp && i!=index){
            temp=temp->next;
            i++;
        }
        if(temp==NULL) return -1;
        return temp->data;
    }
     
    void addAtHead(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    
    void addAtTail(int val){
        Node* newnode=new Node(val);
        if(tail==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    
    void addAtIndex(int index,int val){
        if(index==0) addAtHead(val);
        else{
            int i=0;
            Node* temp=head;
            while(temp && i!=index-1){
                temp=temp->next;
                i++;
            }
            if(temp==NULL) return ;
            if(temp->next==NULL){
                Node* newnode=new Node(val);
                tail->next=newnode;
                tail=tail->next;
            }
            else{
                Node* newnode=new Node(val);
                newnode->next=temp->next;
                temp->next=newnode;
            }
        }
    }
    
    void deleteAtIndex(int index){
        if(index==0) head=head->next;
        else{
            int i=0;
            Node* temp=head;
            while(i!=index-1 && temp){
                temp=temp->next;
                i++;
            }
            if(temp==tail) return;
            if(temp==NULL) return;
            if(temp->next==tail){
                tail=temp;
                temp->next=NULL;
            }
            else{
                Node* delnode=temp->next;
                temp->next=delnode->next;
                delnode->next=NULL;
                delete delnode;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */