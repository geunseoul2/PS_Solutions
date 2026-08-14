class Tweet {
public:
    int userId;
    int idx;
    int tweetId;

    Tweet(int user, int tweet, int idx) : userId(user), tweetId(tweet), idx(idx) {}

    bool operator<(const Tweet t) const {
        return tweetId < t.tweetId;
    }
};

class Twitter {
public:
    unordered_map<int,vector<int>> user_tweet;
    unordered_map<int,unordered_set<int>> user_followee;

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweet[userId].push_back(tweetId);
        user_followee[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        if(user_tweet.find(userId) == user_tweet.end()) return ans;
        priority_queue<Tweet> heap;

        if(user_followee.find(userId) != user_followee.end()) {
            for(const auto& key : user_followee[userId]) {
                int idx = user_tweet[key].size()-1;
                int tweetId = user_tweet[key][idx];
                int userId = key;
                heap.push(Tweet(userId,tweetId,idx));
            }
        }

        while(!heap.empty() && ans.size() < 10) {
            Tweet top = heap.top();
            heap.pop();
            ans.push_back(top.tweetId);
            if(top.idx > 0) {
                int newTweet = user_tweet[top.userId][top.idx-1];
                heap.push(Tweet(top.userId,newTweet,top.idx-1));
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        user_tweet[followerId]; //if the follower does not exist in user data, make it.
        user_followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(user_followee.find(followerId) == user_followee.end()) return;
        if(followerId == followeeId) return; //자기 자신을 unfollow 할수는 없다
        user_followee[followerId].erase(followeeId);
    }
};
