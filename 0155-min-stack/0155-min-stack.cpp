class MinStack{
public:
    stack<pair<int,int>> s;
    MinStack(){
        
    }
    void push(int val){
        if(s.empty()) s.push({val,val});
        else s.push({val,min(val,s.top().second)});
    }
    void pop(){
        s.pop();
    }
    int top(){
        return s.top().first;
    }
    int getMin(){
        return s.top().second;
    }


    //USING 2 STACK
    // stack<int> s1,s2;
    // MinStack(){
        
    // }
    // void push(int val){
    //     if(s2.empty() || s2.top()>=val){
    //         s2.push(val);
    //     }
    //     s1.push(val);
    // }
    // void pop(){
    //     if(s1.top()==s2.top()){
    //         s2.pop();
    //     }
    //     s1.pop();
    // }
    // int top(){
    //     return s1.top();
    // }
    // int getMin(){
    //     return s2.top();
    // }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */