//利用一个栈和一个队列在O(N)时间复杂度解决问题

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
	vector<int> res;
	stack<int> sk;
	queue<int> qe;
	for (int x : A) {
		if (x < 0) {
			sk.push(x*x);
		}
		else{
			qe.push(x*x);
		}
	}
	while (!sk.empty() && !qe.empty()) {
		if (sk.top() < qe.front()) {
			res.push_back(sk.top());
			sk.pop();
		}
		else {
			res.push_back(qe.front());
			qe.pop();
		}
	}
	while (!sk.empty()) {
		res.push_back(sk.top());
		sk.pop();
	}
	while (!qe.empty()) {
		res.push_back(qe.front());
		qe.pop();
	}
	return res;
}
};
