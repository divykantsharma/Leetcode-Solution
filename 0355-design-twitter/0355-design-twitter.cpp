class Twitter{
public:
    stack<pair<int,int>> st;
    set<pair<int,int>> s;
    Twitter(){
        
    }
    void postTweet(int userId,int tweetId){
        st.push({userId,tweetId});
    }
    vector<int> getNewsFeed(int userId){
        vector<int> ans;
        stack<pair<int,int>> temp;
        while(!st.empty() && ans.size()<10){
            auto a=st.top();
            st.pop();
            temp.push(a);
            int user=a.first;
            int tweet=a.second;
            if(s.find({userId,user})!=s.end() || user==userId){
                ans.push_back(tweet);
            }
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return ans;
    }
    void follow(int followerId,int followeeId){
        s.insert({followerId,followeeId});
    }
    void unfollow(int followerId,int followeeId){
        s.erase({followerId,followeeId}); 
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */