class Solution {
public:
    bool isPowerOfTwo(int n){
        for(int i=0;i<32;i++){
            if(n==pow(2,i)){
                return true;
            }
        }
        return false;
    }


    //if number of set bits in a number equals 1 ,then the number is a power of 2
    //Misses on the last test case (1108/1109) testcases passed
    // bool isPowerOfTwo(int n){	
    //     int count=0;
    //     for(int i=0;i<32;i++){
    //         if(n&(1<<i)) count++;
    //     }
    //     return count==1;
    // }
};

