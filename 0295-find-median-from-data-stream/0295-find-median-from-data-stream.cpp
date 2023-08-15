class MedianFinder{
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    MedianFinder(){
        
    }
    
    void addNum(int num){
        if(maxh.empty() || maxh.top()>num) maxh.push(num);
        else minh.push(num);
        int n=maxh.size();      //balancing
        int m=minh.size();
        if(n>m+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(m>n+1){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian(){
        int n=maxh.size();
        int m=minh.size();
        if(n==m) return ((1.0)*(maxh.top()+minh.top()))/2;    //even size
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