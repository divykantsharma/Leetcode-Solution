class RandomizedSet{
public:
    unordered_set<int> st;
    RandomizedSet(){
        
    }
    bool insert(int val){
        if(st.find(val)==st.end()){     //not found case 
            st.insert(val);
            return true;
        }
        else return false;
    }
    bool remove(int val){
        if(st.find(val)==st.end()) return false;
        else{
            st.erase(val);
            return true;
        }
    }
    
    int getRandom(){
        int i=rand()%st.size();
        for(auto it:st){
            if(i==0) return it;
            i--;
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */