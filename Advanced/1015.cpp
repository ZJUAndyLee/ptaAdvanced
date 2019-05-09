#include<vector>
#include<iostream>
#include<math.h>
#include<stack>
#include<unordered_map>
using namespace std;

//一个栈的应用可以解决所有的问题

void Input(vector<pair<int,int>> &vec) {
	while (true) {
		int x, y;
		cin >> x;
		if (x < 0)
			break;
		cin >> y;
		vec.push_back(pair<int, int>(x, y));
	}
}

int Exchange(int num,int rdx){
	stack<int> q;
	while (num > 0) {
		q.push(num%rdx);
		num = num / rdx;
	}
	int res = 0, ct = 0;
	while (!q.empty()) {
		int tmp = q.top();
		q.pop();
		res += tmp * pow(rdx, ct);
		ct++;
	}
	return res;
}

bool isprime(int num) {
	if (num == 1)
		return false;
	if (num == 2)
		return true;
	if (num % 2 != 0) {
		int ct = 3;
		while (ct < num / 2) {
			if (num%ct == 0)
				return false;
			ct += 2;
		}
		return true;
	}
	return false;
}

void ReversiblePrimes(vector<pair<int, int>> &vec) {
	for (auto p : vec) {
		if (isprime(p.first)) {
			int tmpex = Exchange(p.first, p.second);
			if (isprime(tmpex))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}
}


int main() {
	vector<int> N1, N2;
	vector<pair<int, int>> v;
	Input(v);
	ReversiblePrimes(v);

}
