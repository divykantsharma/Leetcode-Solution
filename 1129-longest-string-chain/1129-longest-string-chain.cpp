class Solution {
public:
    bool checkPossible(string& s1,string& s2){
        if(s1.length()!=s2.length()+1) return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;second++;
            }
            else first++;
        }
        if(first==s1.size() && second==s2.size()) return true;
        else return false;
    }
    static bool comp(string& a,string& b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();  //sort acc to the length
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi) maxi=dp[i];
        }
        return maxi;
    }
};
