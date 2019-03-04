//用时12ms其实和1ms代码基本上一致但是好像判断的地方有些不一样 不知道为什么差别这么大

class Solution {
public:
    bool isValid(string s) {
	stack<char> sk;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i])
		{
		case ')':
			if (sk.empty()) return false;
			else if (sk.top() == '(') sk.pop();
			else return false;
			break;
		case ']':
			if (sk.empty()) return false;
			else if (sk.top() == '[') sk.pop();
			else return false;
			break;
		case '}':
			if (sk.empty()) return false;
			else if (sk.top() == '{') sk.pop();
			else return false;
			break;
		default:
			sk.push(s[i]);
			break;
		}
	}
	if(sk.empty())return true;
	else return false;
}
};
