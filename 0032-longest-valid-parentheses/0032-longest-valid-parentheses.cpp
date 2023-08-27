class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else{   //s[i]==')'
                if(st.size()==1){
                    st.top()=i;
                }
                else{
                    st.pop();
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};