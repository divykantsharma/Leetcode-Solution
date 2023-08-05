class Solution {
public:
    int trailingZeroes(int n){
        // if(n<=1) return 0;
        if(n==0) return 0;
        return n/5+trailingZeroes(n/5);
    }


    //TLE - for (n=13) - (13/500) testcases passed
    // int trailingZeroes(int n){
    //     if(n<=1) return 0;
    //     int fact=n;
    //     for(int i=1;i<n;i++){
    //         fact*=(n-i);
    //     }
    //     int trail=0;
    //     while(fact){
    //         if(fact%10==0) trail++;
    //         else break;
    //         fact=fact/10;
    //     }
    //     return trail;
    // }
};