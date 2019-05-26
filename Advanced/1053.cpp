#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
int num,nln,val;
struct node {
	int Id, key;
	node(int x, int y) :Id(x), key(y) {};
};
unordered_map<int, vector<node>> g;
vector<int> nd;
vector<vector<int>> res;

bool cmp(node &v1,node &v2) {
	return v1.key > v2.key ? true : false;
}
void Input() {
	cin >> num >> nln >> val;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		nd.push_back(tmp);
	}
	for (int i = 0; i < nln; i++) {
		int x, tmpi;
		cin >> x >> tmpi;
		for (int i = 0; i < tmpi; i++) {
			int tmp;
			cin >> tmp;
			g[x].push_back(node(tmp, nd[tmp]));
		}
		sort(g[x].begin(), g[x].end(),cmp);
	}
}



void dfs(vector<int> path,int root,int total) {
	total += nd[root];
	if (g.find(root) == g.end()) {
		if (total == val) {
			vector<int> p(path.begin(), path.end());
			p.push_back(nd[root]);
			res.push_back(p);
		}
		return;
	}
	for (auto x : g[root]) {
		if (total > val)
			return;
		vector<int> p(path.begin(), path.end());
		p.push_back(nd[root]);
		dfs( p, x.Id, total);
	}
}

void PathofEqualWeight() {
	vector<int> vec;
	dfs(vec, 0, 0);
	for (auto x : res) {
		for (int i = 0; i < x.size(); i++) {
			if (i == 0)
				cout << x[i];
			else
				cout << " " << x[i];
		}
		cout << endl;
	}
}

int main() {
	Input();
	PathofEqualWeight();

}
