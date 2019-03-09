//经典后缀表达式 又称波兰表达式

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
	int tmp1, tmp2;
	stack<int> stk;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i].size() == 1) {
			switch (tokens[i][0])
			{
			case '+':
				tmp1 = stk.top(); stk.pop();
				tmp2 = stk.top(); stk.pop();
				stk.push(tmp2 + tmp1);
				break;
			case '-':
				tmp1 = stk.top(); stk.pop();
				tmp2 = stk.top(); stk.pop();
				stk.push(tmp2 - tmp1);
				break;
			case '*':
				tmp1 = stk.top(); stk.pop();
				tmp2 = stk.top(); stk.pop();
				stk.push(tmp2 * tmp1);
				break;
			case '/':
				tmp1 = stk.top(); stk.pop();
				tmp2 = stk.top(); stk.pop();
				stk.push(tmp2 / tmp1);
				break;
			default:
				stk.push(stoi(tokens[i]));
				break;
			}
		}
		else {  stk.push(stoi(tokens[i])); }
	}
	return stk.top();
}
};
