class Solution {
public:
    //SIEVE OF ERATOSTHESES
    int countPrimes(int n){
        if(n==0 || n==1) return 0;
        int count=0;
        vector<int> prime(n+1,1);
        prime[0]=prime[1]=0;
        for(int i=2;i<n;i++){
            if(prime[i]==1){
                count++;
                for(int j=2*i;j<n;j+=i){
                    prime[j]=0;
                }
            }
        }
        return count;
    }


    //SIEVE OF ERATOSTHESES - LOVE BABBAR
    // int countPrimes(int n){
    //     int count=0;
    //     vector<bool> prime(n+1,true);
    //     prime[0]=prime[1]=false;
    //     for(int i=2;i<n;i++){
    //         if(prime[i]){
    //             count++;
    //             for(int j=2*i;j<n;j=j+i){
    //                 prime[j]=false;
    //             }
    //         }
    //     }
    //     return count;
    // }


    //TLE
    // bool isPrime(int n){
    //     if(n<=1) return false;
    //     for(int i=2;i<n;i++){
    //         if(n%i==0) return false;
    //     }
    //     return true;
    // }
    // int countPrimes(int n){
    //     int count=0;
    //     for(int i=2;i<n;i++){
    //         if(isPrime(i)) count++;
    //     }
    //     return count;
    // }
};