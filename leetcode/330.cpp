//贪心思路 每次循环都判断数组里面是不是有被cover的数 如果有就把他加上然后 cover范围增大 如果没有就加一个数而这个数正好是第一个没有被cover的数
class Solution {
public:
   int minPatches(vector<int>& nums, int n) {
	int res = 0;
	long long idx = 0;
	int iter = 0;
	int numsSz = nums.size();
	while (idx < n) {
		if (iter < numsSz) {
			if (nums[iter] <= idx + 1) {
				idx += nums[iter];
				iter++;
			}
			else {
				idx += idx + 1;
				res++;
			}
		}
		else {
			idx += idx + 1;
			res++;
		}
	}
	return res;
}

};
