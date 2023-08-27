class Solution {
public:
    vector<int> partitionLabels(string s){
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){   //calculating the last occurence of every char
            mp[s[i]]=i;
        }
        vector<int> ans;
        int st=0,en=0;
        for(int i=0;i<n;i++){
            en=max(en,mp[s[i]]);
            if(en==i){
                ans.push_back(en-st+1);
                st=en+1;
            }
        }
        return ans;
    }
};