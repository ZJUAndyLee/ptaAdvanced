#define MIN -100000000;
int maxcrossing(vector<int>&vec, int mid) {
	int l_sum = MIN; int r_sum = MIN; int sum = 0;
	for (int i = mid; i >= 0; i--) {
		sum += vec[i];
		if (sum > l_sum) l_sum = sum;
	}
	sum = 0;
	for (int i = mid + 1; i < vec.size(); i++) {
		sum += vec[i];
		if (sum > r_sum) r_sum = sum;
	}
	sum = l_sum + r_sum;
	if (l_sum >= sum && l_sum >= r_sum) return l_sum;//用并归的方法求的时候两部分进行合并的时候一定要考虑返回值必须为左和以及右和以及和的最大值
	if (r_sum >= sum && r_sum >= l_sum) return r_sum;
	else return sum;

}

int maxSubArray(vector<int>& nums) {
	if (nums.size() == 1) return nums[0];
	else {
		int l_max, r_max, c_max, mid = nums.size() / 2;
		vector<int> l_a, r_a;
		l_a.insert(l_a.end(), nums.begin(), (nums.begin() + mid));
		r_a.insert(r_a.end(), (nums.begin() + mid), nums.end());
		l_max = maxSubArray(l_a);
		r_max = maxSubArray(r_a);
		c_max = maxcrossing(nums, mid);
		if (l_max >= r_max && l_max >= c_max) return l_max;
		if (r_max >= l_max && r_max >= c_max) return r_max;
		else return c_max;
	}
	
}
