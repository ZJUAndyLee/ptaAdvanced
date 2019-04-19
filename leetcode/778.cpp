//最小堆+dijkstra 在遍历的过程最大的顶点也就是我们需要的值
class Solution {
public:
struct cmp {
	bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>>&p2) {
		return p1.first > p2.first ? true : false;
	}
};

int swimInWater(vector<vector<int>>& grid) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> minHeap;
	int res=0;
	int szG = grid.size();
	if (szG < 1) return 0;
	bool hash[50][50]={false};
	minHeap.push(pair<int, pair<int, int>>(grid[0][0], pair<int, int>(0, 0)));
	while (!minHeap.empty()) {
		pair<int, pair<int, int>> tmp = minHeap.top();
		minHeap.pop();
		int x = tmp.second.first, y = tmp.second.second;
		res = tmp.first > res ? tmp.first : res;
		if (x == szG - 1 && y == szG - 1) { break; }
		hash[x][y] = 1;
		if (x > 0) {
			if (!hash[x - 1][y]) {
				minHeap.push(pair<int, pair<int, int>>(grid[x - 1][y], pair<int, int>(x - 1, y)));
			}
		}
		if (x < szG - 1) {
			if (!hash[x + 1][y]) {
				minHeap.push(pair<int, pair<int, int>>(grid[x + 1][y], pair<int, int>(x + 1, y)));
			}
		}
		if (y > 0) {
			if (!hash[x][y - 1]) {
				minHeap.push(pair<int, pair<int, int>>(grid[x][y - 1], pair<int, int>(x, y - 1)));
			}
		}
		if (y < szG - 1) {
			if (!hash[x][y + 1]) {
				minHeap.push(pair<int, pair<int, int>>(grid[x][y + 1], pair<int, int>(x, y + 1)));
			}
		}
	}
	
	return res;
}

};
