class Solution {
public:
    //INTUTIVE - BASED ON OBSERVATION
    int maxProduct(vector<int>& nums){
        int n=nums.size();
        int ans=INT_MIN;
        int pref=1,suff=1;
        for(int i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref=pref*nums[i];
            suff=suff*nums[n-1-i];
            ans=max(ans,max(pref,suff));
        }
        return ans;
    }


    //MODIFICATION OF KADANE ALGORITHM
    // int maxProduct(vector<int>& nums){
    //     int mx=nums[0];
    //     int product=1;
    //     for(int i=0;i<nums.size();i++){     //collecting max product from beggining 
    //         product=product*nums[i];
    //         mx=max(mx,product);
    //         if(product==0) product=1;
    //     }
    //     product=1;
    //     for(int i=nums.size()-1;i>=0;i--){  //from end 
    //         product=product*nums[i];
    //         mx=max(mx,product);
    //         if(product==0) product=1;
    //     }
    //     return mx;
    // }


    //BRUTE FORCE - TLE - TC-> O(N^2) 
    // int maxProduct(vector<int>& nums){
    //     int mx=INT_MIN;
    //     for(int i=0;i<nums.size();i++){
    //         int temp=1;
    //         for(int j=i;j<nums.size();j++){
    //             temp=temp*nums[j];
    //             mx=max(mx,temp);
    //         }
    //     }
    //     return mx;
    // }
};