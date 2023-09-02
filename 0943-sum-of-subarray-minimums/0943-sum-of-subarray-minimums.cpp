#define MOD (int)(1e9+7)
class Solution {
public:
//APPROACH -> arr[i]*(number of subarrays jisme voh sabse chota hoga ,(i-nsl[i])*(nsr[i]-i)) voh range aise niklegi 
    //ADITYA VERMA APPROACH
    int sumSubarrayMins(vector<int>& arr){     //khudse karna agli baar
            // we need to find the index of the nsl and the nsr element in the array
            vector<int> nsl;
            stack<pair<int,int>> st1;
            for(int i = 0 ; i < arr.size() ; i++){
                if(st1.size()==0) nsl.push_back(-1);
                else if(st1.size() > 0 && st1.top().first < arr[i]){
                    nsl.push_back(st1.top().second);
                }
                else{
                    while(st1.size() > 0 and st1.top().first >= arr[i]){
                        st1.pop();
                    }
                    if(st1.size()==0) nsl.push_back(-1);
                    else nsl.push_back(st1.top().second);
                }
                st1.push({arr[i] , i});
            }
            vector<int> nsr;
            stack<pair<int,int>> st2;
            for(int i = arr.size()-1 ; i >=0  ; i--){
                if(st2.size()==0) nsr.push_back(arr.size());
                else if(st2.size() > 0 && st2.top().first <= arr[i]){   // corner case (vvvvvv important) 
                        nsr.push_back(st2.top().second);
                }
                else{
                    while(st2.size() > 0 and st2.top().first > arr[i]){
                        st2.pop();
                    }
                    if(st2.size()==0) nsr.push_back(arr.size());
                    else nsr.push_back(st2.top().second);
                }        
                st2.push({arr[i] , i});
            }
            reverse(nsr.begin(),nsr.end());
            long long ans=0;
            int M=1e9+7;
            for(int i=0;i<arr.size();i++){
                long long total_ele=(i-nsl[i])*1LL*(nsr[i]-i);
                ans=(ans+total_ele*1LL*arr[i])%M;
            }
            return ans;
        }


    //BRUTE FORCE - TLE - TC->O(N^2) - (77/87) testcases passed
    // int sumSubarrayMins(vector<int>& arr) {
    //     int sum=accumulate(arr.begin(),arr.end(),0);
    //     for(int i=0;i<arr.size();i++){
    //         int mini=INT_MAX;
    //         for(int j=i+1;j<arr.size();j++){
    //             mini=min(mini,min(arr[i],arr[j]));
    //             sum=((sum)%MOD+(mini)%MOD)%MOD;
    //         }
    //     }
    //     return sum;
    // }
};


