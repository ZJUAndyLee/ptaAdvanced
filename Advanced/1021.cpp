//与leetcode的最小高度树是一样的 是BFS反向的一个过程 每次去掉图中度为1的点 最大高度的树肯定是最初度为1的顶点里生成的
//每次我们去掉图中度为1的点最后只剩下小于等于两个点时还满足条件的初始顶点也就是最大高度树的顶点


#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

int Num;
vector<unordered_set<int>> g;
void Input() {
	cin >> Num;
	g.assign(Num + 1, unordered_set<int>());
	for (int i = 1; i < Num; i++) {
		int x, y;
		cin >> x >> y;
		g[x].insert(y);
		g[y].insert(x);
	}
}

void dfs(vector<int>& v,int root) {
	v[root] = 1;
	for (auto x : g[root]) {
		if (v[x] == 0)
			dfs(v, x);
	}
}

void DeepestRoot() {
	if (Num == 1) {
		cout << 1 << endl;
		return;
	}
	vector<int> vis(Num + 1, 0);
	int res = 0;
	for (int i = 1; i < Num + 1; i++) {
		if (vis[i] == 0) {
			dfs(vis, i);
			res++;
		}
	}
	if (res > 1) {
		cout << "Error: " << res << " components";
		return;
	}
	res = 0;
	unordered_map<int, pair<int,int>> mp;
	for (int i = 1; i < Num + 1; i++) {
		if (g[i].size() == 1) {
			int tmp = *(g[i].begin());
			mp[i] = pair<int, int>(tmp, i);
			res++;
		}
	}
	
	if (res < 1) {
		cout << "Error: " << 1 << " components";
		return;
	}
	res = Num;
	while (res > 2) {
		unordered_map<int, int> tmpmp;
		for (auto x : mp) {
			
			g[x.second.first].erase(x.second.second);
			tmpmp[x.first] = x.second.first;
			res--;
		}
		mp.clear();
		for (auto x : tmpmp) {
			if (g[x.second].size() == 1) {//这里要注意不仅仅是顶点度为1的时候 在顶点度为0的时候也需要对顶点进行一波更新
				int tmp = *(g[x.second].begin());
				mp.insert(pair<int, pair<int, int>>(x.first, pair<int, int>(tmp, x.second)));
			}
			else if (g[x.second].size() == 0) {//顶点度为0则说明整个树已经递减到顶点数为1了。
				mp.insert(pair<int, pair<int, int>>(x.first, pair<int, int>(x.second, x.second)));
			}
		}
	}
	vector<int> tmpres;
	for (auto x : mp) {
		tmpres.push_back(x.first);
	}
	sort(tmpres.begin(), tmpres.end());
	for (auto x : tmpres) {
		cout << x << endl;
	}
}


int main() {
	Input();
	DeepestRoot();

 }
