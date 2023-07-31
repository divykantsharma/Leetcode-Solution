class Solution {
public:
    //SIMILAR TO LIS PRINTING
    vector<int> largestDivisibleSubset(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1,lastIndex=0;
        sort(arr.begin(),arr.end());    //1st change
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){    //2nd change
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};