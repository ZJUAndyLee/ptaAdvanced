//用一个堆 类似在线处理

class Solution {
public:
   vector<int> nextGreaterElements(vector<int>& nums) {
	int sz = nums.size();
	vector<int> res(sz, -1);
	if (sz <= 1)
		return res;
	int i = 0, ct = 0;
	stack<int> sk;
	while (i<sz) {
		int j = i + 1;
		if (j == sz)
			j = 0;
		if (nums[j] > nums[i]) {
			res[i] = nums[j];
			while (!sk.empty()) {
				int tmpi = sk.top();
				if (nums[j] > nums[tmpi]) {
					res[tmpi] = nums[j];
					sk.pop();
				}
				else
					break;
			}
		}
		else {
			sk.push(i);
		}
		i++;
	}

	i = 0;
	while (!sk.empty()) {
		int tmpi = sk.top();
		if (tmpi == i)
			break;
		if (nums[tmpi] < nums[i]) {
			res[tmpi] = nums[i];
			sk.pop();
		}
		else {
			i++;
		}
	}
	return res;
}

};
