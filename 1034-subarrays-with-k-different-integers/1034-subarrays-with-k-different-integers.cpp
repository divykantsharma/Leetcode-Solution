//Approach: To directly count the subarrays with exactly K different integers is hard but to find the count of subarrays with at most K different integers is easy. So the idea is to find the count of subarrays with at most K different integers, let it be C(K), and the count of subarrays with at most (K – 1) different integers, let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the required answer.
// Count of subarrays with at most K different elements can be easily calculated through the sliding window technique. The idea is to keep expanding the right boundary of the window till the count of distinct elements in the window is less than or equal to K and when the count of distinct elements inside the window becomes more than K, start shrinking the window from the left till the count becomes less than or equal to K. Also for every expansion, keep counting the subarrays as right – left + 1 where right and left are the boundaries of the current window.
class Solution{
public:
    int atmostSubarray(vector<int>& nums,int k){
        int i=0,j=0;
        int count=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]); 
                    i++;
                }
            }
            if(mp.size()<=k){
                count+=j-i+1;
                j++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums,int k){
        return atmostSubarray(nums,k)-atmostSubarray(nums,k-1);
    }
};