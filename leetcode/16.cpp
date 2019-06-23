//将三数之和转化为两数，然后两数就直接首位的和进行相加得到偏大偏小的两种情况在进一步移动首尾的index

class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(),nums.end());
	int res = nums[0] + nums[1] + nums[2];
	for (int i = 0; i<int(nums.size()); i++) {
		int left = i + 1, right = nums.size() - 1;
		while (left < right) {
			if (abs(nums[i] + nums[right] + nums[left] - target) < abs(res - target)) {
				res = nums[i] + nums[right] + nums[left];
			}
            else
                break;
			if (nums[i] + nums[right] + nums[left] > target)
				right--;
			else
				left++;
		}

	}
	return res;
}
};
