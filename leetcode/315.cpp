//这个是并归O(NlogN)时间复杂度的一个算法 但是由于在并归的过程中元素位置发生了改变 所以我们必须另造一个pair数组然后把进行排序
//这个题最关键的是想到并归之前所有排好序的元素的右边最小值的个数已经得到了 只需要往后面累加就可以了
void mergeSort(vector<pair<int,int>>& nums, vector<int> &res, int st, int ed) {
	if (st == ed) return;
	int mid = (st + ed) / 2;
	mergeSort(nums, res, st, mid);
	mergeSort(nums, res, mid + 1, ed);
	int tmp = mid + 1;
	for (int i = st; i <= mid; i++) {
		while (tmp <= ed && nums[i].first > nums[tmp].first) tmp++;
		res[nums[i].second] += tmp - mid - 1;
	}
	/*vector<int> tmplt, tmprt, reslt, resrt;
	tmplt.insert(tmplt.end(), nums.begin() + st, nums.begin() + mid + 1);
	tmprt.insert(tmprt.end(), nums.begin() + mid + 1, nums.begin() + ed + 1);
	reslt.insert(reslt.end(), res.begin() + st, res.begin() + mid + 1);
	resrt.insert(resrt.end(), res.begin() + mid + 1, res.begin() + ed + 1);
	int iter = 0, jter = 0, k = st;
	while (iter < tmplt.size()&& jter < tmprt.size()) {
		if (tmplt[iter] < tmprt[jter]) {
			nums[k] = tmplt[iter];
			res[k] = reslt[iter];
			iter++;
		}
		else {
			nums[k] = tmprt[jter];
			res[k] = resrt[jter];
			jter++;
		}
		k++;
	}
	while (iter < tmplt.size()) {
		nums[k] = tmplt[iter];
		res[k] = reslt[iter];
		iter++;
		k++;
	}
	while (jter < tmprt.size()) {
		nums[k] = tmprt[jter];
		res[k] = resrt[jter];
		jter++;
		k++;
	}*/
	inplace_merge(nums.begin() + st, nums.begin() + mid + 1, nums.begin() + ed + 1);//[begin,middle) merge [middle,end)
}

vector<int> countSmaller(vector<int>& nums) {
	if(nums.size()<1)return nums;
	vector<int> res(int(nums.size()), 0);
	vector<pair<int,int>> parr;
	for (int i = 0; i < nums.size(); i++) parr.push_back(pair<int, int>(nums[i], i));	
	mergeSort(parr, res, 0, nums.size() - 1);
	return res;
}
