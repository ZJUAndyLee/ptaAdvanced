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

void MaxSubseqSum(vector<int> &vec) {
	pair<int, int> res;
	res.first = vec[0];
	
	int maxsum = -1, tmpsum = 0, tmpst = vec[0];
	for (int i = 0; i < sz; i++) {
		tmpsum += vec[i];
		if (tmpsum > maxsum) {
			res.first = tmpst;
			res.second = vec[i];
			maxsum = tmpsum;
		}
		if (tmpsum < 0) {
			tmpsum = 0;
			if (i < sz - 1)
				tmpst = vec[i + 1];
		}
	}
	if (maxsum < 0) {
		cout << 0 << " " << vec.front() << " " << vec.back();
	}
	else {
		cout << maxsum << " " << res.first << " " << res.second;
	}
}

int main() {
	
	vector<int> seq;
	Input(seq);
	MaxSubseqSum(seq);
}
