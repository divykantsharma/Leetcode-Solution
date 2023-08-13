class Solution{
public:
    bool closeStrings(string word1,string word2){
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int> mp1,mp2;
        for(auto it:word1) mp1[it]++;
        for(auto it:word2) mp2[it]++;
        vector<int> temp1,temp2;
        vector<char> temp3,temp4;
        for(auto it:mp1){
            temp1.push_back(it.second);
            temp3.push_back(it.first);
        }
        for(auto it:mp2){
            temp2.push_back(it.second);
            temp4.push_back(it.first);
        }
        sort(temp1.begin(),temp1.end()); 
        sort(temp2.begin(),temp2.end());
        sort(temp3.begin(),temp3.end());
        sort(temp4.begin(),temp4.end());
        return (temp1==temp2)&&(temp3==temp4);
    }
};