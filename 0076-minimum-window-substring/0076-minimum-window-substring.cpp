class Solution {
public:
    string minWindow(string s,string t){
        unordered_map<char,int> mp;
        for(auto it:t) mp[it]++;
        int count=mp.size();
        int i=0,j=0,MinL=INT_MAX;
        string ans="";
        while(j<s.length()){
            if(mp.count(s[j])>0){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }
            if(count==0){
                if(MinL>j-i+1){
                    ans=s.substr(i,j-i+1);
                    MinL=ans.size();
                }  
                while(count==0){
                    if(mp.count(s[i])>0){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            if(MinL>j-i+1){
                                ans=s.substr(i,j-i+1);
                                MinL=ans.size();
                            }
                        }
                    }
                    i++;                   
                }  
                j++;    
            }
            else j++;
        }
        return ans;
    }
};