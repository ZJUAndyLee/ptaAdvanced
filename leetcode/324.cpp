//这道题实在是太头疼了 有两个地方改到现在也不知道为什么 而且时间用了600ms非常夸张
//看一下前面快的算法是如何实现的吧
//但是我在这里面写好了一个随机查找程序用来查中位数 当然也可以用来查找任何一个顺位的数 且最大时间复杂度为O(N)
int rand_num(int st, int ed) {
	srand(unsigned(time(NULL)));
	int tmp = (rand() % (ed - st + 1));
	tmp += st;
	return tmp;
}

void find_mid(vector<int> &vec, int st, int ed, int idx) {
	if (st == ed) return ;
	int r_num = rand_num(st, ed);
	swap(vec[r_num], vec[ed]);
	int i = st - 1, j = st;
	for (; j < ed; j++) {
		if (vec[j] < vec[ed]) {
			i++; swap(vec[j], vec[i]);
		}
	}
	swap(vec[ed], vec[++i]);
	if (i == idx) return ;
	else if (i > idx) find_mid(vec, st, i - 1, idx);
	else find_mid(vec, i + 1, ed, idx);
}


void wiggleSort(vector<int>& nums) {
	vector<int> bigvec;
	vector<int> smlvec;
	int sz = nums.size();
	if (sz < 2) return;
	find_mid(nums, 0, sz - 1, sz / 2);
	int  j = 0;
	
	smlvec.insert(smlvec.end(), nums.begin(), nums.begin() + sz / 2 );
	bigvec.insert(bigvec.end(), nums.begin() + sz / 2 , nums.end());
	sort(bigvec.begin(), bigvec.end());
	sort(smlvec.begin(), smlvec.end());
	int bsz = bigvec.size(), ssz = smlvec.size(), ct = 0;
	if (bsz > ssz) {
		for (j = ssz-1; j >=0; j--) {
			nums[2 * ct] = min(smlvec[j], bigvec[j+1]);
			nums[2 * ct + 1] = max(smlvec[j], bigvec[j + 1]);
			ct++;
		}
		nums.back() = bigvec[0];
		if (nums[sz - 1] == nums[sz - 2]) {
			if (nums.back() > nums[0] && nums.back() < nums[1]) swap(nums.back(), nums[0]);
			else {
				for (int i = 2; i < sz - 1; i = i + 2) {
					if (nums.back() > nums[i] && nums.back() < nums[i - 1] && nums.back() < nums[i + 1])swap(nums[i], nums.back());
				}
			}
		}
	}
	else{
		for (j = ssz - 1; j >= 0; j--) {
			nums[2 * ct] = min(smlvec[j], bigvec[j]);
			nums[2 * ct + 1] = max(smlvec[j], bigvec[j]);
			ct++;
		}
	}
	
}
