#include<vector>
#include<iostream>
using namespace std;

int sz;

void Input(vector<int> &vec) {
	int tmp;
	cin >> sz;
	for (int i = 0; i < sz; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
}

void Elevator(vector<int> &vec) {
	int tmpf = 0, res = 0;
	for (int i = 0; i < sz; i++) {
		int tmp = vec[i] - tmpf;
		if (tmp > 0) {
			res =res + tmp * 6 + 5;
		}
		else if (tmp < 0) {
			res = res + (-tmp) * 4 + 5;
		}
		else {
			res += 5;
		}
		tmpf = vec[i];
	}
	cout << res;
}

int main() {
	vector<int> seq;
	Input(seq);
	Elevator(seq);

}
