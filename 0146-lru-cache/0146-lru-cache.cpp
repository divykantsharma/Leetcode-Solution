class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val){  //constructor
        this->key=key;
        this->val=val;
    }
};
class LRUCache{
public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;

    LRUCache(int capacity){ 
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node* newnode){ 
        Node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(Node* delnode){ 
        Node* delprev=delnode->prev; 
        Node* delnext=delnode->next;
        delprev->next=delnext; 
        delnext->prev=delprev;
    }
    int get(int key_){ 
        if(mp.find(key_)!=mp.end()){ 
            Node* resnode=mp[key_];
            int res=resnode->val;
            deletenode(resnode);
            addnode(resnode);
            mp[key_]=head->next;
            return res;
        }
        return -1;
    }
    void put(int key_, int value){
        if(mp.find(key_)!=mp.end()){
            Node* existingnode=mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key_,value));
        mp[key_]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */