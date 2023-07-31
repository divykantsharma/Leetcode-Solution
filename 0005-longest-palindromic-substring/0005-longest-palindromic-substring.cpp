class Solution {
public:
/* TABULATION - WRONG WAY , take example - "aacabdkacaa"
output="acaa"
expected output="aca"
We are following the approach striver told in longest palindromic subsequence - which wont work here - as it is returning LCSubstring and not LPSubstring 
Difference is jo standard approach se string aayegi voh aage peeche se toh same hoegi par individually khud ek palindrome ni hei*/
//Therefore changes done :
// string longestPalindrome(string s){
//     int n=s.length();
//     string t=s;  
//     reverse(t.begin(),t.end());
//     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//     int maxi=0,start=0;
//     //no need of base casse as 0 hi daal rahe hei , but we initialized dp with 0
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(s[i-1]==t[j-1]){
//                 dp[i][j]=1+dp[i-1][j-1];
//                 int rIdx=i;
//                 int idx=j-dp[i][j]+1;
//                 if(n-rIdx+1==idx){
//                     if(maxi<dp[i][j]){
//                         maxi=dp[i][j];
//                         start=i;
//                     }
//                 }
//             }
//             else dp[i][j]=0;
//         }
//     }
//     string ans;
//     while(maxi>0){
//         ans.push_back(s[start-1]);
//         start--;maxi--;
//     }
//     return ans;
// }


//Odd Even Method
string longestPalindrome(string s){
        int n=s.length();
        int pos=0,len=1;
        int high,low;
        for(int i=1;i<n;i++){
            low=i;      // for even
            high=i-1;
            while(low>=0 && high<n && s[low]==s[high]){
               if(len<high-low+1){
                   pos=low;
                   len=high-low+1;
               }
               low--,high++;
            }
            low=i-1;    // for odd
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                if(len<high-low+1){
                    pos=low;
                    len=high-low+1;
                    
                }
                low--,high++;
            }
        }
        return s.substr(pos,len);
    }


//LOOPS - TC:O(N^2)*O(N) - MLE - (49/141) testcases passed
//     bool isPalindrome(string s,int start,int end){
//       while(start<=end) {
//         if(s[start]!=s[end]) return false;
//         start++;
//         end--;
//       }
//       return true;
//   }
//     string longestPalindrome(string s){
//         if(s.size()==1) return s;
//         string maxfinal="";
//         for(int index=0;index<s.length();index++){
//             for(int i=index;i<s.length();i++){
//                 string final="";
//                 if(isPalindrome(s,index,i)){
//                     final=s.substr(index,i-index+1);
//                 }
//                 if(final.size()>maxfinal.size()) maxfinal=final;
//             }            
//         }
//         return maxfinal;
//     }
};