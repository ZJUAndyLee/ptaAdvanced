#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<queue>
#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;
int total;

struct pat {
	long long reg;
	int grd, lnum,lrank;
	pat(long long id, int g, int loc) :reg(id), grd(g), lnum(loc) {};
};

bool cmp1(pat &p1,pat &p2) {
	return p1.grd > p2.grd ? true : false;
}

bool cmp2(pat &p1, pat &p2) {
	if (p1.grd > p2.grd) {
		return true;
	}
	else if (p1.grd == p2.grd) {
		if (p1.reg > p2.reg) {
			return false;
		}
		else
			return true;
	}
	else
		return false;
}

void Input(vector<pat> &rank) {
	cin >> total;
	for (int i = 0; i < total; i++) {
		int num;
		cin >> num;
		vector<pat> tmpv;
		for (int j = 0; j < num; j++) {
			long long Id;
			int grade;
			cin >> Id >> grade;
			tmpv.push_back(pat(Id, grade, i + 1));
		}
		sort(tmpv.begin(), tmpv.end(), cmp1);
		int idx = 1;
		if (!tmpv.empty()) {
			tmpv[0].lrank = 1;
			for (int i = 1; i < tmpv.size(); i++) {
				if (tmpv[i].grd == tmpv[i - 1].grd)
					tmpv[i].lrank = idx;
				else {
					idx = i + 1;
					tmpv[i].lrank = idx;

				}
			}
		}
		rank.insert(rank.end(), tmpv.begin(), tmpv.end());
	}
}

void exchange(long long n) {
	int ct = 0;
	stack<int> stk;
	while (ct < 13) {
		stk.push(n % 10);
		n = n / 10;
		ct++;
	}
	while (!stk.empty()) {
		int tmp = stk.top();
		stk.pop();
		cout << tmp;
	}
}

void PATRanking(vector<pat> &rank) {
	sort(rank.begin(), rank.end(), cmp2);
	int idx = 1;
	cout << rank.size() << endl;
	exchange(rank[0].reg);//格式化输出
	cout << " " << idx << " " << rank[0].lnum << " " << rank[0].lrank << endl;
	for (int i = 1; i < rank.size(); i++) {
		if (rank[i].grd == rank[i - 1].grd) {
			exchange(rank[i].reg);
			cout << " " << idx << " " << rank[i].lnum << " " << rank[i].lrank << endl;
		}
		else {
			idx = i + 1;
			exchange(rank[i].reg);
			cout << " " << idx << " " << rank[i].lnum << " " << rank[i].lrank << endl;
		}
	}
}

int main() {
	vector<pat> vec;
	Input(vec);
	PATRanking(vec);
	

 }
