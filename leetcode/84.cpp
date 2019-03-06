//我的最初版本为 N平方暴力求解 唯一优化的地方为如果相邻的两个点相等那么就跳过这个这个点不算
//最终用时超2000ms了
class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
	int max = 0, tmp = 0;
	vector<int>::iterator tmp_up, tmp_down, front = heights.begin(), end = heights.end();
	for (vector<int>::iterator iter = heights.begin(); iter != heights.end(); iter++) {
		tmp_up = iter;
		tmp_down = iter + 1;
		if (!(*iter)) { front = iter; end = heights.end(); }
		if (iter != heights.begin()) { if (*iter == *(iter - 1)) continue; }
		tmp = 0;
		while (1) {
			if (*tmp_up >= *iter) tmp += *iter;
			else { break; }
			if (tmp_up == front)break;
			tmp_up--;
			
		}
		while (1) {
			if (tmp_down >= end) break;
			else if (!(*tmp_down)) { end = tmp_down; break; }
			if (*tmp_down >= *iter)tmp += *iter;
			else break;
			tmp_down++;
			
		}
		max = tmp > max ? tmp : max;
	}
	return max;
}
};

//4ms的算法巧妙的运用了堆以及位置这个概念轻松将时间复杂度大大降低


int largestRectangleArea(vector<int>& heights) {
	stack<int> cache;
	heights.push_back(0);
	int len = heights.size();
	int result = 0;
	for (int i = 0; i < len;)
	{
		if (cache.empty() || heights[i] >= heights[cache.top()])
		{
			cache.push(i);//假如是递增的趋势那么就把递增的数的数组标签存入一个堆中
			i++;
		}
		else
		{
			int idx = cache.top(); //如果发现该数变小 那么只需要把前一个数的位置拿出来计算它这时所形成的矩形面积 一个个拿出来直到当前的数不再大于堆顶端的数 
			cache.pop();
			int area = heights[idx] * (cache.empty() ? i : (i - cache.top() - 1));
			result = area > result ? area : result;
		}
	}
	return result;
}
