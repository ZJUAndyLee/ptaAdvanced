//基数排序希望O(1)的空间复杂这个很简单

class Solution {
public:

void sortColors(vector<int>& nums) {
	int *arr = new int[3];
	arr[0] = 0; arr[1] = 0; arr[2] = 0;
	for (int i = 0; i < nums.size(); i++) arr[nums[i]]++;
	for (int i = 1; i < 3; i++)arr[i] += arr[i - 1];
	int tmp = nums[0], ct = 0, tmp1;
	for (int i = 0; i < arr[0]; i++) nums[i] = 0;
	for (int i = arr[0]; i < arr[1]; i++) nums[i] = 1;
	for (int i = arr[1]; i < arr[2]; i++) nums[i] = 2;
}
};
