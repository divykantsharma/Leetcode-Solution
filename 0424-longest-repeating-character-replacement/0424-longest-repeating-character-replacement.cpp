class Solution{
public:
    int characterReplacement(string s,int k){
        int i=0,j=0;
        int maxi=0,maxiLen=0;
        unordered_map<char,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);
            if((j-i+1)-maxi<=k){
                maxiLen=max(maxiLen,j-i+1);
                j++;
            }
            else if((j-i+1)-maxi>k){
                while((j-i+1)-maxi>k){
                    mp[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxiLen;
    }
};