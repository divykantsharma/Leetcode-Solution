class Solution{
public:
    int countSetBits(int n){
        int count=0;
        while(n){
            n=n&(n-1);  //har iteration mei rightmost set bit ko unset kar raha hei
            count++;
        }
        return count;
    }
    vector<int> countBits(int n){
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countSetBits(i));
        }
        return ans;
    }


    //WITHOUT KNOWLWDGE OF BITS
    // string decimaltobinary(int n){
    //     string ans="";
    //     while(n){
    //         ans=to_string(n%2)+ans;
    //         n=n/2;
    //     }
    //     return ans;
    // }
    // int countone(string s){
    //     int count=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='1') count++;
    //     }
    //     return count;
    // }
    // vector<int> countBits(int n){
    //     vector<int> ans(n+1,0);
    //     for(int i=0;i<=n;i++){
    //         string newa=decimaltobinary(i);
    //         ans[i]=countone(newa);
    //     }
    //     return ans;
    // }
};