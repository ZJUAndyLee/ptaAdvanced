//贪心算法 以当前一跳之后的位置为基础能跳的最远的位置 即为这一跳要跳到的位置
//要注意边界条件
int jump(vector<int>& nums) {
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
		if (tmp < len-1) tmp = max;
	}
	return res;
}

