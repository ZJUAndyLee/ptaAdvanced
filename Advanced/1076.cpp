/**注意 这个题用BFS更好*/

#include <vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

#include <iostream>
using namespace std;

int num, level,vnum;

vector<vector<int>> g;
vector<int> vec;

void Input() {
	scanf("%d %d", &num, &level);
	g.assign(num + 1, vector<int>());
	for (int i = 1; i <= num; i++) {
		int tmpn;
		scanf("%d", &tmpn);
		for (int j = 0; j < tmpn; j++) {
			int tmpi;
			scanf("%d", &tmpi);
			g[tmpi].push_back(i);
		}
	}
	scanf("%d", &vnum);
	for(int i=0;i<vnum;i++){
		int tmpi;
		scanf("%d", &tmpi);
		vec.push_back(tmpi);
	}

}

int BFS(vector<int> &vis,int st) {
	int res = 0,idx=0;
	vis[st] = 1;
	queue<int> qe;
	for (int i = 0; i < g[st].size();i++) {
		if (i == 0)
			idx = g[st][i];
		vis[g[st][i]] = 1;
		qe.push(g[st][i]);
	}
	int l = 0, flagi = 1;
	while (!qe.empty()) {
		int tmp = qe.front();
		qe.pop();
		if (tmp == idx) {
			l++;
			if (l > level)
				break;
			flagi = 0;
		}
		if (flagi == 0) {
			for (int i = 0; i < g[tmp].size(); i++) {
				if (vis[g[tmp][i]] == 0) {
					if (flagi == 0) {
						idx = g[tmp][i];
						flagi = 1;
					}
					vis[g[tmp][i]] = 1;
					qe.push(g[tmp][i]);
				}
			}
		}
		else {
			for (int i = 0; i < g[tmp].size(); i++) {
				if (vis[g[tmp][i]] == 0) {
					vis[g[tmp][i]] = 1;
					qe.push(g[tmp][i]);
				}
			}
		}
		res++;
	}
	return res;
}

void ForwardsonWeibo() {
	vector<int> res;
	for (int i = 0; i < vnum; i++) {
		vector<int> vis(num + 1, 0);
		int tmp = BFS(vis, vec[i]);
		res.push_back(tmp);
	}
	for (int x : res) {
		printf("%d\n", x);
	}
}



int main() {
	Input();
	ForwardsonWeibo();
	

}
