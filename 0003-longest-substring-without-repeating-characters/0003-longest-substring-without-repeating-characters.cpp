class Solution {
public:
    //TC - O(N) -> BY SLIDING WINDOW
    int lengthOfLongestSubstring(string s){
        int n=s.length();
        if(n==0) return 0;
        int i=0,j=0;
        int mx=INT_MIN;
        unordered_map<char,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==j-i+1){   //depicting the length of substring equals number of elements in map
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){   //depicts presence of repeating char
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }


    //TC - O(N^2)
    // int lengthOfLongestSubstring(string s){
    //     int maxcount=0;
    //     for(int i=0;i<s.length();i++){
    //         unordered_map<char,int> map;
    //         int count=0;
    //         for(int j=i;j<s.length();j++){
    //             if(map[s[j]]==0){
    //                 count++;
    //                 map[s[j]]++;
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //         if(count>maxcount) maxcount=count;
    //     }
    //     return maxcount;
    // }
};