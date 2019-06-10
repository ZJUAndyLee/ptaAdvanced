//DFS基础题

#include <iostream>
#include<vector>
using namespace std;

int num;
double base, per;
vector<vector<int>> g;
vector<int> wt;
void Input() {
	cin >> num >> base >> per;
	g.assign(num, vector<int>());
	wt.assign(num, 0);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {
			for (int j = 0; j < tmp; j++) {
				int tmpi;
				scanf("%d", &tmpi);
				g[i].push_back(tmpi);
			}
		}
		else {
			int tmpi;
			scanf("%d", &tmpi);
			wt[i] = tmpi;
		}
	}
}

void DFS(int root,double &res,double price) {
	if (g[root].empty()) {
		res += price * wt[root];
		return;
	}
	else {
		for (auto x : g[root]) {
			DFS(x, res, price + price * (per / 100.0));
		}
	}
}


int main() {
	Input();
	double res = 0.0;
	DFS(0, res, base);
	printf("%.1f", res);

}
