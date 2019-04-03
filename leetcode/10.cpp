
//动态规划 问题的子结构要搞清楚 搞不清就无法实现动态规划
class Solution {
public:
   
bool isMatch(string s, string p) {
	int ssz = s.size(), psz = p.size();
	bool **hash = new bool*[ssz + 1];
	for (int i = 0; i <= ssz; i++) {
		hash[i] = new bool[psz + 1];
	}
	for (int i = 0; i <= ssz; i++) {
		hash[i][0] = 0;
	}
	hash[0][0] = 1;
	for (int i = 0; i <= ssz; i++) {
		for (int j = 1; j <= psz; j++) {
			if (p[j - 1] == '*') {
				if (hash[i][j - 2]) {
					hash[i][j] = 1;
				}
				else {
					if (i > 0) {
						if (hash[i - 1][j]) {
							if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                                hash[i][j] = 1;
							}
							else hash[i][j] = 0;
						}
						else hash[i][j] = 0;
					}
					else hash[i][j] = 0;
				}
			}

			else {
				if (i > 0) {
					if (hash[i - 1][j - 1]) {
						if (s[i - 1] == p[j - 1] || p[j - 1] == '.') hash[i][j] = 1;
						else hash[i][j] = 0;
					}
					else { hash[i][j] = 0; }
				}
				else {
					hash[i][j] = 0;
				}
			}
		}
	}
	return hash[ssz][psz];
}
};
