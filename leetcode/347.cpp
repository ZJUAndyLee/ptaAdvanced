//用一个最大堆排序把所有的数的频数记录下来 最后把记录下来的数组排序一下即可 时间复杂度为O(nlgn)

vector<int> topKFrequent(vector<int>& nums, int k) {
	priority_queue<int> maxheap(nums.begin(), nums.end());
	vector<pair<int, int>> tmp;
	vector<int>res;
	int ct , val;
	while (!maxheap.empty()) {
		ct = 0;
		val = maxheap.top();
		maxheap.pop(); ct++;
		while (!maxheap.empty()&&val == maxheap.top()) {
			maxheap.pop(); ct++;
		}
		tmp.push_back(pair<int, int>(ct, val));
	}
	sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
	for (int i = 0; i < k; i++) res.push_back(tmp[i].second);
	return res;
}
