class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);    
        for(int i=0;i<n;i++){
            hash[i]=i; 
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]> dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }   
        int ans=-1;
        int lastIndex=-1;
        for(int i=0;i<=n-1;i++){
            if(dp[i]>ans){
                ans=dp[i];    //updating the LIS or maxi
                lastIndex=i;  //storing the index that has maximum value in dp 
            }
        }
        vector<int> temp;   //backtracking starts from here
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){ 
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);    
        }
        reverse(temp.begin(),temp.end());   //as we backtracked so elements are stored in a reverse order
        return temp;
    }
};