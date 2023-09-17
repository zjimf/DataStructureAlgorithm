/** 355. Design Twitter
 * @brief build two map
 *        1. follow map<userId, followId>
 *        2. post map <userId, pair<timePost, tweetId>>
 *
 */
#define pii pair<int, int>
class Twitter {
private:
    int timePost = 0;
    unordered_map<int, set<int>> followMap;
    unordered_map<int, vector<pii>> postMap;

public:
    Twitter() {}

    // O(logn)
    void postTweet(int userId, int tweetId) {
        followMap[userId].insert(userId);
        postMap[userId].push_back({timePost++, tweetId});
    }
    // O(mlogm)
    vector<int> getNewsFeed(int userId) {
        priority_queue<pii> maxHeap;
        set<int> userFollows = followMap[userId];
        // O(n*m), n:user nums, m:post nums
        for (const auto &follow : userFollows)
            for (auto p : postMap[follow])
                maxHeap.push(p);

        // O(mlogm)
        vector<int> feeds;
        int size = maxHeap.size() >= 10 ? 10 : maxHeap.size();
        for (int i = 0; i < size; i++) {
            feeds.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feeds;
    }

    // O(logn)
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    // O(logn)
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
