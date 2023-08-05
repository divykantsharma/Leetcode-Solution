class Solution {
public:
    int partitionString(string s){
        int res=1;
        unordered_map<int,int> m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])!=m.end()){
                m.clear();
                res++;
            }
            m[s[i]]++;
            
        }
        return res;    
    }
};