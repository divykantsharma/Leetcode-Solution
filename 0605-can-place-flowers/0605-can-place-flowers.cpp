class Solution{
public:
    bool canPlaceFlowers(vector<int>& flowerbed,int n){
        int count=0;
        flowerbed.insert(flowerbed.begin(),0);      //start mei 0 insert karwa diya 
        flowerbed.push_back(0);
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                count++;
                flowerbed[i]=1;
            }
        }
        if(n<=count) return true;
        return false;
    }
};