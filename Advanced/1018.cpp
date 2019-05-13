#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

//dijsktra+DFS 不知道为啥有几个点过不了下一次再来吧 弄了很久了

int Nmax, v, sp, e;
#define INT_MAX 2147483647
void Input(vector<vector<pair<int, int>>> &g, vector<int> &num) {
	cin >> Nmax >> v >> sp >> e;
	g.assign(e, vector<pair<int, int>>());
	num.push_back(0);
	for (int i = 1; i <= v; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back(pair<int, int>(y, z));
	}

}

pair<int, int> dfs(vector<vector<int>> &path, vector<int> &vmin, vector<int> &num, int root) {
	pair<int, int> min(INT_MAX, INT_MAX);
	if (path[root].empty()) {
		return pair<int, int>(0, 0);
	}
	for (auto x : path[root]) {
		pair<int, int> tmp = dfs(path, vmin, num, x);

		if (Nmax / 2 - num[root] > 0) {
			if (tmp.second > 0) {
				if (tmp.second > Nmax / 2 - num[root])
					tmp.second -= Nmax / 2 - num[root];
				else {
					tmp.first += Nmax / 2 - num[root] - tmp.second;
					tmp.second = 0;
				}
			}
			else
				tmp.first += Nmax / 2 - num[root];
		}
		else {
			tmp.second += num[root] - Nmax / 2;
		}

		if (tmp.first < min.first) {
			min = tmp;
			vmin[x] = root;
		}
		else if (tmp.first == min.first) {
			if (tmp.second < min.second) {
				min = tmp;
				vmin[x] = root;
			}
		}
	}

	return min;
}

void PublicBikeManagement(vector<vector<pair<int, int>>> &g, vector<int> &num) {
	vector<int> dis(v + 1, INT_MAX);
	vector<int> vis(v + 1, 0);
	vis[0] = 1;
	dis[0] = 0;
	vector<vector<int>> path(v + 1, vector<int>());
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		vis[tmp] = 1;
		for (auto x : g[tmp]) {
			if (vis[x.first] == 0) {
				if (dis[x.first] > dis[tmp] + x.second) {
					dis[x.first] = dis[tmp] + x.second;
					q.push(x.first);
					path[x.first].clear();
					path[x.first].push_back(tmp);
				}
				else if (dis[x.first] == dis[tmp] + x.second) {
					q.push(x.first);
					path[x.first].push_back(tmp);
				}
			}
		}
	}

	vector<int> vmin(v + 1, sp);

	pair<int, int> res = dfs(path, vmin, num, sp);
	res.first = res.first > 0 ? res.first : 0;
	res.second = res.second > 0 ? res.second : 0;
	cout << res.first << " " << 0;
	int tmpI = 0;
	while (tmpI != sp && tmpI <= v) {
		cout << "->" << vmin[tmpI];
		tmpI = vmin[tmpI];
	}
	cout << " " << res.second;


}

int main() {
	vector<vector<pair<int, int>>> edge;
	vector<int> node;
	Input(edge, node);
	PublicBikeManagement(edge, node);

}
