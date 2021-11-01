/**
 * leetcode [355.] 设计推特
输入
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
输出
[null, null, [5], null, null, [6, 5], null, [5]]

解释
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // 用户 1 发送了一条新推文 (用户 id = 1, 推文 id = 5)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含一个 id 为 5 的推文
twitter.follow(1, 2);    // 用户 1 关注了用户 2
twitter.postTweet(2, 6); // 用户 2 发送了一个新推文 (推文 id = 6)
twitter.getNewsFeed(1);  // 用户 1 的获取推文应当返回一个列表，其中包含两个推文，id 分别为 -> [6, 5] 。推文 id 6 应当在推文 id 5 之前，因为它是在 5 之后发送的
twitter.unfollow(1, 2);  // 用户 1 取消关注了用户 2
twitter.getNewsFeed(1);  // 用户 1 获取推文应当返回一个列表，其中包含一个 id 为 5 的推文。因为用户 1 已经不再关注用户 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-twitter
 */
#include <bist/stdc++.h>

using namespace std;
class Twitte
{
public:
    Twitte() {

    }

    void postTweet(int userId, int tweetId) {
        tws.push({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        stack<pair<int, int>> tmp = tws;
        while (ans.size() < 10 && !tmp.empty()) {
            pair<int, int> tw = tmp.top();
            if (userId == tw.fist || (folls[userId].count(tw.first)) ) {
                ans.push_back(tw.second);
            }
            tmp.pop();
        }
    }

    void follow(int followerId, int followeeId) {
        follos[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto it = folls.find(followeeId);
        if (it != folls.end()) {
            folls[followerId].erase(followeeId);
        }
    }

private:
    // 账号 -> 关注的账号（set）使用 set 可以避免重复关注的时候重复插入
    unordered_map<int, unordered_set<int>> folls;
    // 发送的推特用户 推特 Id 使用 stack pair
    stack<pair<int, int>> tws;
};