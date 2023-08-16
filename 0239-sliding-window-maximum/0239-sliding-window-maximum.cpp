class Solution {
public:
    //USING DEQUE - LIST and DEQUE are completely same bas l ki jagah par dq likh do
    vector<int> maxSlidingWindow(vector<int>& nums,int k){
        vector<int> ans;
        deque<int>dq;
        int i=0,j=0;
        while(j<nums.size()){
            while(dq.size()>0 && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]){
                    dq.pop_front();
                }
                i++;
                j++;
            } 
        }
        return ans;
    }


    //USING LIST
    // vector<int> maxSlidingWindow(vector<int>& nums,int k){
    //     vector<int> ans;
    //     list<int> l;
    //     int i=0,j=0;
    //     while(j<nums.size()){
    //         while(l.size()>0 && l.back()<nums[j]){
    //             l.pop_back();
    //         }
    //         l.push_back(nums[j]);
    //         if(j-i+1<k) j++;
    //         else if(j-i+1==k){
    //             ans.push_back(l.front());
    //             if(l.front()==nums[i]){
    //                 l.pop_front();
    //             }
    //             i++;
    //             j++;
    //         } 
    //     }
    //     return ans;
    // }


    //USING PRIORITY QUEUE
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     priority_queue<pair<int,int>>pq;    //max priority queue
    //     int i=0,j=0;
    //     while(j<nums.size()){
    //         pq.push({nums[j],j});
    //         if(j-i+1<k) j++;
    //         else if(j-i+1==k){
    //             while(pq.top().second<i)        
    //             pq.pop();
    //             ans.push_back(pq.top().first);
    //             i++;
    //             j++;
    //         } 
    //     }
    //     return ans;
    // }
};