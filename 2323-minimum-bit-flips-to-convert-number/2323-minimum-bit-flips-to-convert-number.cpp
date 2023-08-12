class Solution{
public:
    int minBitFlips(int a,int b){ 
        int count=0; 
        while(a || b){
            if((a&1)!=(b&1)) count++; 
            a=a>>1; 
            b=b>>1;
        }
        return count;
    }
};