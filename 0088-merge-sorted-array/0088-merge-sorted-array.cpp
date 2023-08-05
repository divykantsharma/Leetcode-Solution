class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }

    // BASIC APPROACH - STANDARD SOLUTION
    //     vector<int> temp;
    //     int i=0,j=0;
    //     while((i<m)&&(j<n)){
    //         if(nums1[i]<=nums2[j]){
    //             temp.push_back(nums1[i]);
    //             i++;
    //         }
    //         else{
    //             temp.push_back(nums2[j]);
    //             j++;
    //         }
    //     }
    //     while(i<m){
    //         temp.push_back(nums1[i]);
    //         i++;
    //     }
    //     while(j<n){
    //         temp.push_back(nums2[j]);
    //         j++;
    //     }
    //     for(int i=0;i<m+n;i++){
    //         nums1.pop_back();
    //     }
    //     for(int i=0;i<temp.size();i++){
    //         nums1.push_back(temp[i]);
    //     }
    // }
};