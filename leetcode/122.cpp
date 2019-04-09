//贪心策略 每次都看明天能不能赚钱 能的话就买 不能就不买


int maxProfit(vector<int>& prices) {
	int res = 0, sz = prices.size();
	for (int i = 0; i < sz -1; i++) {
		res += prices[i + 1] > prices[i] ? prices[i + 1] - prices[i] : 0;
	}
	return res;
}
