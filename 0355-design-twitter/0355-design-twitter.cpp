class Twitter {
public:
    int cnt;
    vector<set<int>>followers;
    vector<priority_queue<pair<int,int>>>feed;
    Twitter() {
        cnt=0;
        followers.resize(501);
        feed.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        feed[userId].push({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int>ans;
       priority_queue<pair<int,int>>pq=feed[userId];
       for(auto x:followers[userId])
       {
           priority_queue<pair<int,int>>t=feed[x];
           while(!t.empty())
           {
             pq.push(t.top());
             t.pop();
           }
       }
       int c=0;
       while(!pq.empty()&&c<10)
       {
          ans.push_back(pq.top().second);
          pq.pop();
          c++;
       }
       return ans;
    }
    
    void follow(int followerId, int followeeId) {
       followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       followers[followerId].erase(followeeId);
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