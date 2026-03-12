#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

class Twitter {
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back(tweetId);
        tweet_times[tweetId] = ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> following;
        if (user_following.find(userId) != user_following.end()) {
            following = user_following[userId];
        }
        unordered_set<int> all_users = following;
        all_users.insert(userId);

        priority_queue<pair<int,int>> tweets;

        for (auto user : all_users) {
            if (user_tweets.find(user) != user_tweets.end()) {
                auto& curr_user = user_tweets[user];
                if (!curr_user.empty()) {
                    int tweets_add = min(10, (int)curr_user.size());
                    for (int i = curr_user.size() - 1; i >= (int)curr_user.size() - tweets_add; i--) {
                        int id = curr_user[i];
                        tweets.push({tweet_times[id], id});
                    }
                }
            }
        }

        vector<int> news_feed;
        while (!tweets.empty() && news_feed.size() < 10) {
            news_feed.push_back(tweets.top().second);
            tweets.pop();
        }
        return news_feed;
    }
    
    void follow(int followerId, int followeeId) {
        user_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (user_following.find(followerId) != user_following.end()) {
            user_following[followerId].erase(followeeId);
        }
    }

private:
    unordered_map<int, vector<int>> user_tweets;
    unordered_map<int, unordered_set<int>> user_following;
    unordered_map<int,int> tweet_times;
    int timestamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}