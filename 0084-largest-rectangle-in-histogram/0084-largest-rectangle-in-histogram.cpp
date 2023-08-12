class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        //NSL - nearest smaller left is calculated
        vector<int> left;
        stack<pair<int,int>> s1;
        int pseudoindex1=-1;
        for(int i=0;i<heights.size();i++){
            if(s1.size()==0){
                left.push_back(pseudoindex1);
            }
            else if(s1.size()!=0 && s1.top().first<heights[i]){
                left.push_back(s1.top().second);
            }
            else if(s1.size()!=0 && s1.top().first>=heights[i]){
                while(s1.size()!=0 && s1.top().first>=heights[i]){
                    s1.pop();
                }
                if(s1.size()==0) left.push_back(pseudoindex1);
                else left.push_back(s1.top().second);
            }
            s1.push({heights[i],i});
        }
        
        //NSR - nearest smaller right is calculated
        vector<int> right;
        stack<pair<int,int>> s2;
        int pseudoindex2=heights.size();
        for(int i=heights.size()-1;i>=0;i--){
            if(s2.size()==0){
                right.push_back(pseudoindex2);
            }
            else if(s2.size()!=0 && s2.top().first<heights[i]){
                right.push_back(s2.top().second);
            }
            else if(s2.size()!=0 && s2.top().first>=heights[i]){
                while(s2.size()!=0 && s2.top().first>=heights[i]){
                    s2.pop();
                }
                if(s2.size()==0) right.push_back(pseudoindex2);
                else right.push_back(s2.top().second);
            }
            s2.push({heights[i],i});
        }
        reverse(right.begin(),right.end());

        // making an area vector and returning the maximum element in the vector , which is avilable at the last position in the sorted vector
        vector<int> area;
        for(int i=0;i<heights.size();i++){
            int z=heights[i]*(right[i]-left[i]-1);
            area.push_back(z);
        }
        return *max_element(area.begin(),area.end());
        // sort(area.begin(),area.end());
        // return area[heights.size()-1];
    }
};
