class Solution{
public:
    bool checkValidString(string s){
        stack<int> open,star;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!open.empty()){
            if(star.empty()) return false;
            else if(star.top()>open.top()){
                open.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};