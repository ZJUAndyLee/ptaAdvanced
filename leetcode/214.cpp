//利用kmp算法得到最长的回文子串
//也就是将自身直接逆转然后和原串进行比较
class Solution {
public:
   	void get_nextval(const string & T, vector<int>&next){//next数组得到不同字串的前后相同的字串的位置的数组
		next[0] = -1;
		for (int i = 1; i < int(T.size()); i++) {
			int j = next[i - 1];
			while ((T[j + 1] != T[i]) && j >= 0)
				j = next[j];
			if (T[j + 1] == T[i])
				next[i] = j + 1;
			else
				next[i] = -1;
		}
	}
	//返回字串T在主串中第pos个字符之后的位置，若不存在，则函数返回0
	//T非空，1<=pos<=length(s)
	int Index_KMP( string& S,  string& T)//算出最长回文字串的位置
	{
		int i = 0, j = 0;
		int m = T.size();
		vector<int> next(m, 0);
		get_nextval(T, next);
		while (i<int(S.size())) {
			if (S[i] == T[j]) {
				i++, j++;
			}
			else {
				if (j == 0)
					i++;
				else {
					j = next[j - 1] + 1;
				}
			}
		}
		return j;
	}
	bool is(const string& str) { //判断是否回文串
		int i = 0, j = str.size() - 1;
		while (i < j) {
			if (str[i++] != str[j--])
				return false;
		}
		return true;
	}
	string shortestPalindrome(string s) {
		if (s.empty() || is(s))  return s;
		string T = s;
		reverse(T.begin(), T.end());
		int idx = Index_KMP(T, s);
		//cout << idx << endl;
		string sub = s.substr(idx, int(s.size()) - idx);
		reverse(sub.begin(), sub.end());
		return sub + s;
	}
};
