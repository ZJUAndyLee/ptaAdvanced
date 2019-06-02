//最大堆 以及贪心思路

#include <vector>
#include<iomanip>
#include<queue>
#include <iostream>
using namespace std;
vector<double> wei;
vector<double> pri;
priority_queue<pair<double, int>> qe;

int num, total;

void Input() {
	cin >> num >> total;
	for (int i = 0; i < num; i++) {
		double tmp;
		cin >> tmp;
		wei.push_back(tmp);
	}
	for (int i = 0; i < num; i++) {
		double tmp;
		cin >> tmp;
		pri.push_back(tmp);
		qe.push(pair < double, int>(tmp / wei[i], i));
	}
}


int main() {
	Input();
	double tmpi = 0;
	double res = 0.0;
	while (!qe.empty()) {
		pair<double, int> pr = qe.top();
		qe.pop();
		if (tmpi + wei[pr.second] < total) {
			tmpi += wei[pr.second];
			res += pri[pr.second];
		}
		else {
			double num = total - tmpi;
			res += num * pr.first;
			break;
		}
	}
	printf("%.2f", res);

}
