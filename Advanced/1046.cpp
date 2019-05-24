// 动态规划的思路 用两个方向的累加来存下来 来解决重复计算的问题

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int num, val;
vector<int> M;
vector<pair<int,int>> List;
void Input() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		M.push_back(tmp);
	}
	cin >> val;
	for (int i = 0; i < val; i++) {
		int x,y;
		cin >> x >> y;
		List.push_back(pair<int, int>(x, y));
	}
}
void ShortestDistance() {
	vector<int> d1(num + 1, 0), d2(num + 1, 0);
	int tmps = 0;
	for (int i = 0; i < num; i++) {
		tmps += M[i];
		d1[i + 1] = tmps;
	}
	tmps = 0;
	for (int i = num - 1; i >= 0; i--) {
		tmps += M[i];
		d2[i] = tmps;
	}
	vector<int> res;
	for (auto x : List) {
		int tmpx = x.first > x.second ? x.first : x.second;
		int tmpy = x.first > x.second ? x.second : x.first;
		
		if (tmpx == tmpy) {
			res.push_back(0);
		}
		else {
			int tmp1 = d1[tmpx - 1] - d1[tmpy - 1];
			int tmp2 = d1[tmpy - 1] + d2[tmpx - 1];
			int tmpmax = tmp1 < tmp2 ? tmp1 : tmp2;
			res.push_back(tmpmax);
		}
	}
	for (int x : res) {
		printf("%d\n",x);
	}
}




int main() {
	Input();
	ShortestDistance();
	//system("pause");
}
