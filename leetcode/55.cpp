//跳跃游戏 基于跳跃游戏Ⅱ因为贪心算法能满足所有的情况 所以当贪心算法 无法跳出循环时说明不能跳到最后
bool canJump(vector<int>& nums) {
	int len = nums.size();
	vector<int> dp(len, 0);
	int tmp = 0, res = 0;
	while(tmp<len-1){
		int max = tmp;
		for (int j = 0; j <= nums[tmp]; j++) {
			if (tmp + j >= len-1) {
				tmp += j;
				break;
			}
			else {
				if (nums[tmp + j] + tmp + j > nums[max]+max) {
					max = tmp + j;
				}
			}
		}
		res++;
		if (tmp == max) return false;
		if (tmp < len-1) tmp = max;
	}
	return true;
}
