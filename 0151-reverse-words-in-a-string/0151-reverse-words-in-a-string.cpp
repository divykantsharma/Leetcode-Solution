class Solution{
public:
    string reverseWords(string s){
        if(s.size()==0) return s;
        stack<string> st;
        string result;
        for(int i=0;i<s.size();i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ){ //store continuous letters into word
                word += s[i]; i++;
            }
            st.push(word); //push word to the stack
        }
        while(!st.empty()){
            result+=st.top(); 
            st.pop();
            if(!st.empty()) result += " ";
        }
        return result;
    }
};