class Solution{
public:
//why we are adding extra (end-j) to count?
//Ans - because by adding this we are actually considering all those substrings which are bigger in size than current substring and also fully contains our current substring!!!
//By using Sliding Window when we get 1st window containing a,b,c then the num of valid substrings will be - 1+(remaining chars outside the window)
    int numberOfSubstrings(string s){
        int i=0,j=0,end=s.size()-1;
        unordered_map<char,int> mp;
        int count=0;
        while(j!=s.size()){
            mp[s[j]]+=1;
            while(mp['a'] and mp['b'] and mp['c']){
                count+=1+(end-j);
                mp[s[i]]-=1; 
                i++;
            }
            j++;
        }
        return count;
    }


    //TLE - (23/54) testcases passed , TC->O(N^3)
    // int numberOfSubstrings(string s){
    //     set<char> st1{'a','b','c'};
    //     int count=0;
    //     for(int i=0;i<s.length();i++){
    //         for(int j=i;j<s.length();j++){
    //             string temp=s.substr(i,j-i+1);
    //             set<char> st2;
    //             for(auto it:temp) st2.insert(it);
    //             if(st2==st1) count++;
    //         }
    //     }
    //     return count;
    // }
};