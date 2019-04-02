//动态规划 一次性AC mark一下

string longestPalindrome(string s) {
		int sz = s.size();
		bool hash[1000][1000] = { 0 };
		for (int i = 0; i < sz; i++) {
			hash[i][i] = 1;
		}
		pair<int, int>maxpair(0,0);
		for (int l = 2; l <= sz; l++) {
			
			for (int i = 0; i < sz - l + 1; i++) {
				int j = i + l - 1;
				if (l == 2) {
					if (s[i] == s[j]) {
						hash[i][j] = 1;
						maxpair.first = i; maxpair.second = j;
					}
				}
				else {
					if (hash[i + 1][j - 1]) {
						if (s[i] == s[j]) {
							hash[i][j] = 1;
							maxpair.first = i; maxpair.second = j;
						}
					}
				}
			}
		}
		string res = s.substr(maxpair.first, maxpair.second - maxpair.first + 1);
		return res;
	}
