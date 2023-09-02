class Solution{
public:
    //MEMOIZATION
    int f(string& s,unordered_set<string>& st,int index,vector<int>& dp){
        if(index>=s.length()) return 0;
        if (dp[index] != -1) return dp[index];
        string temp="";
        int minExtra=s.length();
        for(int i=index;i<s.length();i++){
            temp.push_back(s[i]);
            int tempExtra=(st.count(temp)?0:temp.length());
            int nextExtra=f(s,st,i+1,dp);
            int totalExtra=tempExtra+nextExtra;
            minExtra=min(minExtra,totalExtra);
        }
        return dp[index]=minExtra;
    }
    int minExtraChar(string s,vector<string>& dictionary){
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        // for(string it:dictionary) mp[it]++;
        vector<int> dp(s.length(),-1);
        return f(s,st,0,dp);
    }


    //RECURSION - TLE (6/2028) TC passed
    // int f(string& s,unordered_map<string,int>& mp,int index){
    //     if(index>=s.length()) return 0;
    //     string temp="";
    //     int minExtra=s.length();
    //     for(int i=index;i<s.length();i++){
    //         temp.push_back(s[i]);
    //         int tempExtra=(mp.count(temp)?0:temp.length());
    //         int nextExtra=f(s,mp,i+1);
    //         int totalExtra=tempExtra+nextExtra;
    //         minExtra=min(minExtra,totalExtra);
    //     }
    //     return minExtra;
    // }
    // int minExtraChar(string s,vector<string>& dictionary){
    //     unordered_map<string,int> mp;
    //     for(string it:dictionary) mp[it]++;
    //     return f(s,mp,0);
    // }
};