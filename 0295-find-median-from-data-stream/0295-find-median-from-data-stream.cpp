class MedianFinder{
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder(){
        
    }
    
    void addNum(int num){
        if(maxh.empty() && minh.empty()){
            maxh.push(num);
        }
        else{
            if(maxh.top()<num) minh.push(num);
            else maxh.push(num);
        }
        int n=maxh.size();      //balancing
        int m=minh.size();
        if(n-m==2 || n-m==-2){
            if(n>m){
                int temp=maxh.top();
                maxh.pop();
                minh.push(temp);
            }
            else{
                int temp=minh.top();
                minh.pop();
                maxh.push(temp);
            }
        }
    }
    
    double findMedian(){
        int n=maxh.size();
        int m=minh.size();
        if((n+m)%2==0) return ((1.0)*(maxh.top()+minh.top()))/2;    //even size
        else return (n>m)?maxh.top():minh.top();        //odd size
    }


    //TLE - TC->O(NlogN) , (16/21) testcases passed
    // vector<int> temp;
    // MedianFinder(){
        
    // }

    // void addNum(int num){
    //     temp.push_back(num);
    //     sort(temp.begin(),temp.end());
    // }
    
    // double findMedian(){
    //     if(temp.size()%2==1){
    //         return temp[temp.size()/2];
    //     }
    //     else{
    //         int first=temp[temp.size()/2];
    //         int second=temp[(temp.size()/2)-1];
    //         return ((1.0)*(first+second))/2;
    //     }
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */