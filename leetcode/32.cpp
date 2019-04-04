//动态规划 测试用例 220/230 超时 但是我在本机上跑是300ms不知道为什么
int longestValidParentheses(string s) {
	int slen = s.size();
	bool **hash = new bool*[slen + 1];
	for (int i = 0; i <= slen; i++) {
		hash[i] = new bool[slen + 1];
	}
	for (int i = 1; i <= slen; i++) {
		hash[i][i - 1] = 1;
	}
	int maxlen = 0;
	for (int len = 2; len <= slen; len += 2) {
		for (int i = 0; i < slen+1-len; i++) {
			int j = i + len - 1;
			if (hash[i + 2][j]) {
				if (s[i] == '('&&s[j] == ')') {
					hash[i + 1][j + 1] = 1;
					maxlen = len;
				}
				else hash[i + 1][j + 1] = 0;
			}
			else {
				int k = i + 1;
				for (; k < j - 1; k += 2) {
					if (hash[i + 1][k + 1] && hash[k + 2][j + 1]) {
						hash[i + 1][j + 1] = 1;
						maxlen = len;
						break;
					}
				}
				if (k == j) {
					hash[i + 1][j + 1] = 0;
				}
			}
		}
	}
	return maxlen;
}


//在线处理 做这个题非常简单  又用到了数组下标栈 这个真的很难想到要加大练习
int longestValidParentheses(string s) {
	stack<int> stk;
	int start = -1, maxlen = 0, len = 0;
	int  slen = s.size();
	for (int i = 0; i < slen; i++) {
		if (s[i] == '(') {
			stk.push(i);//'('左括号直接入栈
		}
		else if (!stk.empty()) {
			stk.pop();//右括号且栈不空则把栈顶的'('抛出 并且判断栈是否为空 不为空则用当前下标减去栈顶的数 栈为空则用当前下标减去start
			len = stk.empty() ? i - start : i - stk.top();
			maxlen = max(len, maxlen);
		}
		else {//若为右括号且栈为空 则需要要把start后移到当前数组下标的位置
			start = i;
		}
	}
	return maxlen;
}
