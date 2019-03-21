//运用一个hash表和一个队列可以解决此问题

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> hash;
		char tmp = 'a';
		for (int i = 0; i < 26; i++) {
			tmp += i;
			hash[tmp] = 0;
		}
		queue<char> stk;
		int len = 0; int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!hash[s[i]]) {
				len++;
				stk.push(s[i]);
				hash[s[i]]++;
			}
			else {
				while (!stk.empty() && stk.front() != s[i]) {
					hash[stk.front()]--;
					stk.pop();
					len--;
				}
				if (!stk.empty()) {
					hash[stk.front()]--;
					stk.pop();
					len--;
				}
				stk.push(s[i]);
                hash[s[i]]++;
				len++;
			}
			res = max(len, res);
		}
		return res;
	}
};

//一个代码简洁的算法同样建立一个哈希表但是不需要建立队列只需要每次判断字符串的起点是否发生改变 什么时候发生改变呢？ 就是当有重复的的字符出现的时候
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int>v(128,0);
        int t=0;int ans=0;
        for(int i=0;i<s.length();i++)
        {
            t=max(t,v[s[i]]);
            ans=max(ans,i-t+1);
            v[s[i]]=i+1;
        }
        return ans;
    }             
};
