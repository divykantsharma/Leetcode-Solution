class Solution {
public:
    // USING MIN PRIORITY QUEUE AND COMPARATOR - TC->O(NlogK)
    class comp{
        public:
        bool operator()(int a,int b){
            return a>b;
        }
    };
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int,vector<int>,comp> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }


    // USING MIN PRIORITY QUEUE - TC->O(NlogK)
    // int findKthLargest(vector<int>& nums, int k){
    //     priority_queue<int,vector<int>,greater<int>> pq;
    //     for(int i=0;i<nums.size();i++){
    //         pq.push(nums[i]);
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
    //     return pq.top();
    // }


    // USING MAX PRIORITY QUEUE - TC->O(NlogN)
    // int findKthLargest(vector<int>& nums, int k){
    //     priority_queue<int,vector<int>,less<int>> pq;
    //     // priority_queue<int> pq;
    //     for(int i=0;i<nums.size();i++){
    //         pq.push(nums[i]);
    //     }
    //     int ans=0;
    //     for(int i=1;i<=k;i++){
    //         if(i==k){
    //             ans=pq.top();
    //             pq.pop();
    //             break;
    //         }
    //         pq.pop();
    //     }
    //     return ans;
    // }
};