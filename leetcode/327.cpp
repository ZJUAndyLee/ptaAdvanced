//这个题很巧妙的运用了归并排序 由于无法直接得到结果 你必须事先对要求的数组进行累加求和得到一个新的数组
//然后在新的数组进行归并排序 在归并的过程中由于你左边是有序的 右边也是有序的 其实你只要看右边的数减左边的数是否在区间里面
int mergeSort(vector<long long> &sum, int lower, int upper,int st,int ed) {
	if (st == ed) {
		return sum[st] >= lower && sum[st] <= upper? 1 : 0;
	}
	int mid = (st + ed) / 2;
	int leftct=mergeSort(sum, lower, upper, st, mid);
	int rightct = mergeSort(sum, lower, upper, mid + 1, ed);
	int ct = 0, n = mid + 1, m = mid + 1;//你每次进行判断的时候 m,n不需要重置 因为你的m和n的指标对一个较小的数成立的话 对于较大的数不成立也是递增的
  //所以在这里也就体现了算法Nlog(N)时间复杂度。
	for (int i = st; i <= mid; i++) {
		while (n <=ed && sum[n] - sum[i] < (long long)lower) n++;
		
		while (m <= ed && sum[m] - sum[i] <= (long long)upper) m++;
		if (m - n  > 0) {
			
			ct += m - n ;
		}
	}
	inplace_merge(sum.begin() + st, sum.begin() + mid + 1, sum.begin() + ed + 1); //[start,middle) merge [middle,end);
	return leftct + rightct + ct;
}


int countRangeSum(vector<int>& nums, int lower, int upper) {
	if (nums.size() < 1) {
		return 0;
	}
	vector<long long> sum;
	long long tmp = 0;
	for (int i = 0; i < nums.size(); i++) {
		tmp += nums[i];
		sum.push_back(tmp);
	}
	int res;
	res = mergeSort(sum, lower, upper, 0, sum.size() - 1);
	return res;
}
