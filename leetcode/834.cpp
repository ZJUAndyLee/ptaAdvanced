//这个题我结合英文网站的高赞回答 自己证明了 算法的正确性：

class Solution {
public:
vector<int> res;
vector<int> ct;
vector<unordered_set<int>> g;
void dfs1(int root,int pre) {
	for (auto x : g[root]) {
		if (x == pre) continue;
		dfs1(x, root);
		ct[root] += ct[x];
		res[root] += res[x] + ct[x];
	}
}

void dfs2(int root, int pre) {
	for (auto x : g[root]) {
		if (x == pre) continue;
		res[x] = res[root] + ct.size() - 2 * ct[x];
		dfs2(x, root);
	}
}

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
	ct.assign(N, 1);
	res.assign(N, 0);
	g.assign(N, unordered_set<int>());
	for (auto &x : edges) {
		g[x[0]].insert(x[1]);
		g[x[1]].insert(x[0]);
	}

	dfs1( 0, -1);
	dfs2( 0, -1);
	return res;
}
};
