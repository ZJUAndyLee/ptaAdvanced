/**这是一道典型的动态规划问题：
  首先我们要考虑的是问题的子问题到底是什么？
  那么在这个问题下我们的子问题是什么？
  首先我们假设amount的需要的coins的个数为dp[amount]，而硬币的数组为coins那么我们有 对于所有的硬币我们的状态方程为：
  dp[amount]=min(for(int x:coins){dp[amount-x]} )+1,也就是假设我们最后拿一颗硬币然后amount-x需要多少个硬币 然后找到最小值+1也就是我们当前amount
  需要的硬币个数。***/
  
  int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
		sort(coins.begin(), coins.end());
		vector<int> dp(amount + 1, -1);
		for (int i = 1; i <= amount; i++) {
			int tmpres = INT_MAX;
			for (int tmp : coins) {
				if (tmp<i) {
					if (dp[i - tmp]>0)
						tmpres = min(dp[i - tmp],tmpres);
				}
				else if (tmp == i) {
					tmpres = 0;
				}
				else
					break;
			}
			if (tmpres<INT_MAX) {
				dp[i] = tmpres + 1;
			}
		}
		return dp[amount];
	}
  
  //简化版：
  int coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end());
	int *dp = new int[amount + 1];
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		int tmpres = INT_MAX;
		for (int tmp : coins) {
			if (tmp <= i) {
				if (dp[i - tmp] != INT_MAX) {
					tmpres = min(dp[i - tmp] + 1, tmpres);
				}
			}
            else
                break;
		}
		dp[i] = tmpres;
	}
	return dp[amount] == INT_MAX ? -1 : dp[amount];
}
