class Solution {
public: 
    int maxVowels(string s, int k){
        unordered_set<char> st={'a','e','i','o','u'};
        int i=0,j=0,countVowels=0;
        int maxi=INT_MIN;
        while(j<s.length()){
            if(st.find(s[j])!=st.end()) countVowels++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                maxi=max(maxi,countVowels);
                if(st.find(s[i])!=st.end()) countVowels--;
                i++;
                j++;
            }
        }
        return maxi;
    }
};