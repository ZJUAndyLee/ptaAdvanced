//DFS 得到顶点个数 然后每条边的权重和等于入度之和 总的权重和等于每个点遍历边时的权重和相加的一半

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>

#include<map>
using namespace std;
int N, K;

unordered_map<string,unordered_map<string, int>> g;
unordered_map<string,int> vis;
void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str1, str2;
		int t;
		cin >> str1 >> str2 >> t;
		if (g.find(str1) == g.end()) {
			g[str1][str2] = t;
			g[str2][str1] = t;
		}
		else {
			if (g[str1].find(str2) == g[str1].end()) {
				g[str1][str2] = t;
				g[str2][str1] = t;
			}
			else {
				g[str1][str2] += t;
				g[str2][str1] += t;
			}
		}
		vis[str1] = vis[str2] = 0;
	}
}

pair<string,int> dfs(int &n,int &t,string root) {
	int total = 0;
	vis[root] = 1;
	n++;
	pair<string, int> max(root, 0);
	for (auto x : g[root]) {
		pair<string, int> tmp;
		if (vis[x.first] == 0) {
			tmp = dfs(n, t, x.first);
			if (max.second < tmp.second) {
				max = tmp;
			}
		}
		t += x.second;
		total += x.second;
	}
	if (total > max.second) {
		max.second = total;
		max.first = root;
	}
	return max;
}

void HeadofAGang(){
	map<string, int> res;
	for (auto x : vis) {
		if (x.second == 0) {
			int num = 0, total = 0;
			pair<string, int> tmp = dfs(num, total, x.first);
			total = total / 2;
			if (num >= 3 && total>K) {
				res[tmp.first] = num;
			}
		}
	}
	cout << res.size() << endl;
	for (auto x : res) {
		cout << x.first << " " << x.second << endl;
	}
}

int main() {
	Input();
	HeadofAGang();
	

}
