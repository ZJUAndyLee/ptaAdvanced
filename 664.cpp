//这种求一个长串的字符的问题 可以多想想动态规划 我感觉动态规划需要更多的经验



//对于我们的dp数组我们有
// 1，i==j dp[i][j]=1; i-j==1 dp[i][j]=2;
//2, 初始情况是 dp[i][j]=dp[i][j-1]+1 相当于加一个全新的字符所以总的转化次数+1， 然后我们遍历 i<=k<j 当s[k]==s[j]时我们有 dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1)
//如何证明 我只能给一个若证明 当s[k]==s[j] 时我们总可以找到一个s[k-1]!=s[k]的k点然后有dp[k][j]==dp[k+1][j]  而dp[i][k-1] = dp[i][k]-1 一般地当所有的字符相等时上面式子同样成立
int strangePrinter(string s) {
	int num = s.size();
    if(num<1) return 0;
	vector<vector<int>> dp(num+1, vector<int>(num+1, 0));
	for (int i = 0; i < num; i++) {
		dp[i][i] = 1;
	}
	for (int l = 2; l <= num; l++) {
		for (int i = 0; i < num - l + 1; i++) {
			int j = i + l - 1;
			if (l == 2) {
				if (s[i] == s[j])
					dp[i][j] = 1;
				else
					dp[i][j] = 2;
			}
			else {
				dp[i][j] = dp[i][j - 1] + 1;
				for (int k = i ; k < j; k++) {//i<=k<j 一定要注意卡了很久
					if (s[k] == s[j]) {
						int tmp = dp[i][k] + dp[k + 1][j] - 1;
						dp[i][j] = min(dp[i][j], tmp);
					}
				}
			}
		}
	}
	return dp[0][num - 1];
