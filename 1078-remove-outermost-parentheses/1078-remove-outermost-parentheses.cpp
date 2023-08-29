class Solution {
public:
    // string removeOuterParentheses(string s){
    //     string res;
    //     int count=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='('){
    //             if(count>0) res+=s[i];
    //             count++;
    //         }
    //         else{
    //             if(count>1) res+=s[i];
    //             count--;
    //         }
    //     }
    //     return res;
    // }


    //USING STACK
    string removeOuterParentheses(string s){
        string res;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(st.size()>0) res+=s[i];
                st.push(s[i]);
            }
            else{
                if(st.size()>1) res+=s[i];
                st.pop();
            }
        }
        return res;
    }
};