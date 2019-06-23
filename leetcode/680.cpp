//从两头开始验证找到第一个不相等的字符然后分两种情况进行判断
class Solution {
public:
    bool validPalindrome(string s) {
		int sz = s.size();
		int i = 0, j = sz - 1;
		bool flag1 = true, flag2 = true;
		while (i<=j) {
			if (s[i] != s[j]) {
				int i1 = i + 1, j1 = j;
				while (i1 <= j1) {
					if (s[i1] != s[j1]) {
						return false;
					}
					i1++,j1--;
				}
				int i2 = i, j2 = j - 1;
				while (i2 <= j2) {
					if (s[i2] != s[j2]) {
						flag2 = false;
						break;
					}
					i2++, j2--;
				}
				break;
			}
			i++, j--;
		}
		return flag1 || flag2;
	}
};
