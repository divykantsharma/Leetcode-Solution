class Solution{
public:
    int jump(vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=max(i+nums[i],nums[i-1]);
        }
        int jumps=0,i=0;
        while(i<n-1){
            jumps++;
            i=nums[i];
        }
        return jumps;
    }
};