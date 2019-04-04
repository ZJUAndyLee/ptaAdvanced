//与前面的那到动规题非常类似 关键点还是寻找子问题的结构 把逻辑理清楚。

class Solution {
public:
   bool isMatch(string s, string p) {
	int slen = s.size(), plen = p.size();
	bool **hash = new bool*[slen + 1];
	for (int i = 0; i <= slen; i++) {
		hash[i] = new bool[plen + 1];
	}
	hash[0][0] = 1;
	for (int i = 1; i <= slen; i++) {
		hash[i][0] = 0;
	}
	for (int i = 0; i <= slen; i++) {
		for (int j = 1; j <= plen; j++) {
			if (p[j - 1] != '*') {
				if (i>0) {
					if (hash[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?')) {
						hash[i][j] = 1;
						
					}
					else {
						hash[i][j] = 0;
					}
				}
				else {
					hash[i][j] = 0;
				}
			}
			else {
				if (hash[i][j - 1] || (i > 0 && hash[i - 1][j])) {
					hash[i][j] = 1;

				}
				else {
					hash[i][j] = 0;
				}
			}
		}
	}
	return hash[slen][plen];
}
};
