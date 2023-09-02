class Solution{
public:
    string removeKdigits(string num,int k){
        if(k>=num.size()) return "0";
        stack<char> s;
        for(int i=0;i<num.size();i++){
            if(s.empty()) s.push(num[i]);
            else{
                while(!s.empty() && s.top()>num[i] && k>0){
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        while(k>0){         //stack is ready after this loop
            s.pop();
            k--;
        }
        if(s.empty()) return "0";   //important check
        string ans;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;        //to remove the leading zeros
        while(ans[i]=='0'){
            i++;
        }
        return (ans.substr(i)=="")?"0":ans.substr(i);
    }
};