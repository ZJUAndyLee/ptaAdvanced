//dfs 单点超时
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

int N, M,K;

void Input(vector<pair<int,int>> &e,vector<int> &node) {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x,y;
		cin >> x >> y;
		e.push_back(pair<int, int>(x, y));
	}
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		node.push_back(tmp);
	}
	
}

void dfs(vector<unordered_set<int>> &g, vector<int> &v,int root) {
	v[root] = 1;
	for (auto x : g[root]) {
		if (!v[x])
			dfs(g, v, x);
	}
}

void battleOverCity(vector<pair<int, int>> &e, vector<int> &node) {
    vector<unordered_set<int>> g(N + 1, unordered_set<int>());
	for (int i = 0; i < M; i++) {
		g[e[i].first].insert(e[i].second);
		g[e[i].second].insert(e[i].first);
	}
	for (int i = 0; i < K; i++) {
		int tmp = node[i];
        vector<int> vis(N + 1, 0);
		vis[tmp]=1;
		int res = 0;
		for (int i = 1; i < N + 1; i++) {
			if (vis[i] == 0 && i != tmp) {
				dfs(g, vis, i);
				res++;
			}
		}
		if (N <2) cout << 0 << endl;
		else
			cout << res - 1 << endl;
	}
}

int main() {
	vector<pair<int, int>> edge;
	vector<int> node;
	Input(edge, node);
	battleOverCity(edge, node);

}
