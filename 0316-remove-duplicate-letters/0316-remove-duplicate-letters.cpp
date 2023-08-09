class Solution{
public:
    string removeDuplicateLetters(string s){
        map<char,int> mp,vis;
        for(auto it:s) mp[it]++;
        string res="";
        for(auto it:s){
            mp[it]--;
            if(!vis[it]){
                while(res.size()>0 && res.back()>it && mp[res.back()]>0){
                    vis[res.back()]=0;
                    res.pop_back();   
                }
                res+=it;
                vis[it]=1;   
            }   
        }
        return res;
    }
};