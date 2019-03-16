//一开始没有明白题目的意思浪费了很多时间 这个题我用链表的方式存储关注的信息 在处理很多细节的地方其实是有些麻烦的 不过好在最后还是完成了 用时140ms

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
	}
	struct node
	{    
		node(){}
		int val;
		node *next;
	};
	node *np(int v) {
		node *tmp = new node;
		tmp->val = v;
		tmp->next = NULL;
		return tmp;
	}
	bool findd(node *ptr,int val) {
		node *tmp = ptr;
		while (tmp) {
			if (tmp->val == val)break;
			tmp = tmp->next;
		}
		return tmp ? true : false;
	}
	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		news.push_back(pair<int, int>(userId, tweetId));
		int i = 0;
		for ( ; i < friends.size(); i++) {
			if (friends[i]->val == userId) break;
		}
		if (i == friends.size()) {//这里并不是所有的发推特的都是一个新的用户 我们需要判断他是不是我们的新的用户再决定是否push。
			node *ptr = np(userId);
			friends.push_back(ptr);
		}
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> res;
		int ct = 0;
		node *tmp=NULL;
		for (int i = 0; i < friends.size(); i++) {
			//cout << friends[i]->val << endl;
			if (friends[i]->val == userId) tmp = friends[i];
		}
		if (tmp) {
			for (int i = news.size() - 1; i >= 0; i--) {
				if (findd(tmp, news[i].first)) {
					res.push_back(news[i].second); ct++;
				}
				if (ct == 10)break;
			}
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (friends.empty()) { 
			node *ptr = np(followerId);
			node *tmp = np(followeeId);
			ptr->next = tmp;
			friends.push_back(ptr);
		}
		else {
			int i = 0;
			for (; i < friends.size(); i++) {
				if (friends[i]->val == followerId) {
					node* tmp = friends[i];
					while (tmp->next) tmp = tmp->next;
					tmp->next = np(followeeId);
					break;
				}
			}
			if (i == friends.size()) {
				node *ptr = np(followerId);
				node *tmp = np(followeeId);
				ptr->next = tmp;
				friends.push_back(ptr);
			}
		}
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		for (int i=0; i < friends.size(); i++) {
			if (friends[i]->val == followerId) {
				node* tmp = friends[i];
				while (tmp->next&&tmp->next->val!=followeeId) tmp = tmp->next;
				if(tmp->next) tmp->next = tmp->next->next;
				break;
			}
		}
	}
private:
	vector<pair<int,int>> news;
	vector<node *> friends;
};
