//要理解深度优先搜索与广度优先搜索的区别，广度优先搜索能找到两点之间边个数最小的路径，而本题是一道很经典的DFS题目 尽可能的对图进行遍历 可以得到当前结点到
//最终结点的所有路径 然后再在路径中选择满足自己条件的路径
class Solution {
public:
	int path = 0, res = 0;
	void dfs(vector<vector<int>>& g,vector<vector<int>> &v,int x,int y,int ct) {
		if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || v[x][y] ||g[x][y] == -1) return;//以上情况直接返回
		if (g[x][y] == 1) v[x][y] = 1;
		if (g[x][y] == 2 ){
			if (ct == path) {//这就是目的路径的条件
				
				res++;
			}
			return;
		}
		if (g[x][y] == 0) {//访问数组表示存在
			v[x][y] = 1;
			ct++;
		}
		
		dfs(g, v, x - 1, y, ct);
		dfs(g, v, x + 1, y, ct);
		dfs(g, v, x, y - 1, ct);
		dfs(g, v, x, y + 1, ct);
		if (g[x][y] == 0) {//这个地方比较关键访问数组在当前路径的深搜索结束之后，在返回前要把自己重置为未访问结点
			v[x][y] = 0;
		}
	}

	int uniquePathsIII(vector<vector<int>>& grid) {
		vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));//建一个访问数组
		int stx = 0, sty = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					stx = i;
					sty = j;
				}
				if (grid[i][j] == 0) {
					path++;
				}
			}
		}
		dfs(grid, vis, stx, sty, 0);
		return res;
	}
};
