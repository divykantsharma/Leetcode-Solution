//CALCULATING SUM1 AND SUM2
class Solution {
public:
    int solve(vector<int>& nums,int sum1,int sum2,bool turn,int i,int j){
        if(i>j) return sum1>=sum2;
        if(turn){   // turn==1 means player 1 turn 
            return solve(nums,sum1+nums[i],sum2,false,i+1,j) || 
                                solve(nums,sum1+nums[j],sum2,false,i,j-1);
        }
        else
           return solve(nums,sum1,sum2+nums[i],true,i+1,j) &&  
                                solve(nums,sum1,sum2+nums[j],true,i,j-1);        
    }
    bool PredictTheWinner(vector<int>& nums){
        int n=nums.size();
        return solve(nums,0,0,true,0,n-1);
    }
};


//CALCULATING ONLY SUM1
//here we will just calculate the maximum possible sum for player 1 , and after that we will subtract this from total sum of nums , then we will get the sum for player 2
// class Solution {
// public:
//     int solve(vector<int>& nums,bool turn,int i,int j){
//         if(i>j) return 0;
//         if(turn){   //player 1 turn
//             return max(nums[i]+solve(nums,false,i+1,j),nums[j]+solve(nums,false,i,j-1));
//         }
//         else
//             return min(solve(nums,true,i+1,j),solve(nums,true,i,j-1));   
//     }
//     bool PredictTheWinner(vector<int>& nums){
//         int totalSum=accumulate(nums.begin(),nums.end(),0);
//         int sum1= solve(nums,true,0,nums.size()-1);
//         int sum2=totalSum-sum1;
//         return sum1>=sum2;
//     }
// };