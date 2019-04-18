//这道题也是没有很多思路 因为错误的条件很难去理解：
//1.有两个父节点的的节点是有问题的
//2.成环

class Solution {
public:
	int findPar(int *p,int x) {
	while (p[x] != x) { x = p[x]; }
	return x;
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	int vis[1001] = { 0 }, sz = edges.size();
	vector<int> tmpa,tmpb;
	for (int i = 0; i < sz; i++) {//第一次遍历为找是否有两个父结点的结点
		if (!vis[edges[i][1]]) {
			vis[edges[i][1]] = edges[i][0];
		}
		else {
			tmpa = { vis[edges[i][1]],edges[i][1] };
			tmpb = { edges[i][0],edges[i][1] };
			edges[i][1] = 0;//这个是为了区别到底是哪个结点引起的问题
			break;
		}
	}
	for (int i = 0; i <= sz; i++) vis[i] = i;//然后进行合并查找
	for (auto &e:edges) {
		if (e[1] == 0) continue;//如果遇到了父节点有两个的结点的某一条边先跳过
		int x = findPar(vis, e[0]);//出现问题的条件是 当前边的父结点的父结点与当前边的子节点相等了 说明有问题了
		if (x == e[1]) {//判断是成环导致的还是有两个父结点的结点导致的
			if (tmpa.empty()) return e;
			return tmpa;
		}
		vis[e[1]] = e[0];
	}
	return tmpb;//如果不是tmpa的问题且有两个父结点的结点存在 则说明是另一条边的原因
}
};
