//h指数这道题比较简单 

int hIndex(vector<int>& citations) {
	if (citations.size() < 1)return 0;
	priority_queue<int> maxheap(citations.begin(), citations.end());
	int tmp = maxheap.top(), ct = 1;
	if (!tmp)return 0;
	while (!maxheap.empty()) {
		if (tmp >= ct) {
			maxheap.pop();
			tmp = maxheap.top();
			ct++;
		}
		else break;
	}
	return ct - 1;
}
