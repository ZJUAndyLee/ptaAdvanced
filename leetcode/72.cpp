//动态规划 子问题结构：如果当前字符相等那么dis[j][i] = dis[j - 1][i - 1];
//如果当前字符不相等那么 就找前面三种情况中最小的一个再+1； min(min(dis[j - 1][i], dis[j][i - 1]),dis[j-1][i-1]) 
//因为当前匹配的情况可以由dis[j - 1][i], dis[j][i - 1]删掉一个字符以及dis[j-1][i-1])替换一个字符得到
//注意初始化的情况把所有的‘0’行都需要对应另一个字符串的长度的操作数。

class Solution {
public:
  int minDistance(string word1, string word2) {
	int w1 = word1.size();
	int w2 = word2.size();
	int **dis = new int*[w1 + 1];
	for (int i = 0; i <= w1; i++) {
		dis[i] = new int[w2 + 1];
	}
	for (int i = 1; i <= w1; i++) {
		dis[i][0] = i;
	}
	for (int i = 1; i <= w2; i++) {
		dis[0][i] = i;
	}
	dis[0][0] = 0;
	for (int i = 1; i <= w2; i++) {
		for (int j = 1; j <= w1; j++) {
			if (word1[j - 1] == word2[i - 1]) {
				dis[j][i] = dis[j - 1][i - 1];
			}
			else {
				dis[j][i] = min(min(dis[j - 1][i], dis[j][i - 1]),dis[j-1][i-1]) + 1;
			}
		}
	}
	return dis[w1][w2];
}
};
