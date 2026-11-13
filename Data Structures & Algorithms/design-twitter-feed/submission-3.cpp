#include <atomic>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Twitter {
  using Timestamp = std::uint64_t;

  // 1. Move Structs to the top so everything below knows what they are
  struct Tweet {
    int poster_id{};
    int tweet_id{};
    Timestamp time_posted{};
  };

  struct User {
    int user_id{};
    std::vector<Tweet> tweets{};
    std::vector<int> following{};  // Flat vector is fine if we guard duplicates!
  };

  struct PQ_Comparator {
    bool operator()(const Tweet& left, const Tweet& right) const {
      return left.time_posted < right.time_posted;
    }
  };

 public:
  Twitter() = default;

  void postTweet(int userId, int tweetId) {
    users_[userId].user_id = userId;  // Ensure profile fields are initialized
    users_[userId].tweets.push_back(
        Tweet{
            .poster_id = userId,
            .tweet_id = tweetId,
            .time_posted = get_time()
        }
    );
  }

  std::vector<int> getNewsFeed(int userId) {
    std::vector<int> res{};
    std::priority_queue<Tweet, std::vector<Tweet>, PQ_Comparator> news_feed;

    // Fix: Captured by const reference! Zero copies.
    const auto& user = users_[userId];

    std::ranges::for_each(user.tweets, [&](const auto& t) { news_feed.push(t); });

    for (size_t i{0}; i < user.following.size(); ++i) {
      // Guard against cases where we follow an ID that hasn't posted a tweet yet
      if (users_.contains(user.following[i])) {
        std::ranges::for_each(users_.at(user.following[i]).tweets,
                              [&](const auto& t) { news_feed.push(t); });
      }
    }

    int ct{0};
    while (!news_feed.empty() && ct < 10) {
      res.push_back(news_feed.top().tweet_id);
      news_feed.pop();
      ++ct;
    }

    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) return;

    // Ensure both users are explicitly realized in the system map first
    users_[followerId].user_id = followerId;
    users_[followeeId].user_id = followeeId;

    // Guard against duplicate followings inside our vector
    auto it = std::ranges::find(users_[followerId].following, followeeId);
    if (it == users_[followerId].following.end()) {
      users_[followerId].following.push_back(followeeId);
    }
  }

  void unfollow(int followerId, int followeeId) {
    if (!users_.contains(followerId)) return;

    auto& following_list = users_[followerId].following;
    auto it = std::ranges::find(following_list, followeeId);

    if (it != following_list.end()) {
      following_list.erase(it);
    }
  }

 private:
  std::unordered_map<int, User> users_;

  [[nodiscard]]
  Timestamp get_time() {
    static std::atomic<Timestamp> t{0};
    return ++t;
  }
};
