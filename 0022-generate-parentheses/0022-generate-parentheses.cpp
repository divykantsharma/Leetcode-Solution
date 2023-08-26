class Solution {
public:
    void f(int open,int close,string temp,vector<string>& ans){
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }
        if(open>0){
            f(open-1,close,temp+'(',ans);
        }
        if(close>open){
            f(open,close-1,temp+')',ans);
        }
    }
    vector<string> generateParenthesis(int n){
        string temp="";
        vector<string> ans;
        int open=n,close=n;
        f(open,close,temp,ans);
        return ans;
    }
};