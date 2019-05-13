#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

//进制转换一个堆加一个队列解决问题

void GeneralPalindromicNumber(int num,int rdx) {
	if (num == 0) {
		cout << "Yes" << endl;
		cout << 0;
		return;
	}
	stack<int> sk;
	queue<int> qe;
	while (num > 0) {
		int tmp = num % rdx;
		sk.push(tmp);
		qe.push(tmp);
		num = num / rdx;
	}
	vector<int> res;
	int idx = 0;
	while (!sk.empty()) {
		if (sk.top() != qe.front()) {
			idx = 1;
		}
		res.push_back(sk.top());
		sk.pop(), qe.pop();
	}
	if (idx == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i == 0)
			cout << res[i];
		else
			cout << " " << res[i];
	}
}


int main() {
	int num, idx;
	cin >> num >> idx;
	GeneralPalindromicNumber(num, idx);

}
