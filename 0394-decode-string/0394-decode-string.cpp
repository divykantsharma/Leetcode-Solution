class Solution{
public:
    //[ isse just pehle ek integer hoga 
    string decodeString(string s){
        stack<char> st;
        for(auto it:s){
            if(it!=']') st.push(it);
            else{
                string temp="";
                while(st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();       //removes '['
                string freq="";
                while(!st.empty() && isdigit(st.top())){
                    freq=st.top()+freq;
                    st.pop();
                }
                int numFreq=stoi(freq);
                while(numFreq--){
                    for(auto it:temp) st.push(it);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};