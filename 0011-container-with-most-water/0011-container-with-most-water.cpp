class Solution {
public:
    int maxArea(vector<int>& height) {
        //OPTIMIZED APPROACH - TC : O(N)
        int n=height.size();
        int left=0;
        int right=n-1;
        int area=0;
        while(left<right){
            int length=right-left;
            int breadth=min(height[left],height[right]);
            area=max(area,length*breadth);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return area;

        
        //NAIVE APPROACH - TC : O(N^2)
        // int maximum=0;
        // for(int i=0;i,height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int breadth=j-i; 
        //         int length=min(height[i],height[j]);
        //         maximum=max(maximum,length*breadth);
        //     }
        // }
        // return maximum;
    }
};