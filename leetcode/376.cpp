//摆动序列 这道题用dp也能做但是判断条件有点多而且时间复杂度也高
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
	int  numsSz = nums.size();
    if(numsSz<2) return numsSz;
	int **dp = new int *[numsSz];
	int **idx = new int *[numsSz];
	for (int i = 0; i < numsSz; i++) {
		dp[i] = new int[numsSz];
		idx[i] = new int[numsSz];;
		idx[i][i] = 0;
		dp[i][i] = 1;
	}
	//idx=1 >  ,   idx = 2 <  , idx = 0 =
	for (int l = 2; l <= numsSz; l++) {
		for (int i = 0; i < numsSz - l + 1; i++) {
			int j = i + l - 1;
			if (j - i == 1) {
				if (nums[i] > nums[j]) {
					idx[i][j] = 2;
					dp[i][j] = 2;
				}
				else if (nums[i] < nums[j]) {
					idx[i][j] = 1;
					dp[i][j] = 2;
				}
				else {
					idx[i][j] = 0;
					dp[i][j] = 1;
				}
			}
			else {
				if (nums[j] - nums[j-1] > 0 && idx[i][j-1] == 2) {
					dp[i][j] = dp[i][j - 1] + 1;
					idx[i][j] = 1;
				}
				else if (nums[j] - nums[j - 1]<0 && idx[i][j - 1] == 1) {
					dp[i][j] = dp[i][j - 1] + 1;
					idx[i][j] = 2;
					
				}
				else if (nums[j] - nums[j - 1] == 0) {
					dp[i][j] = dp[i][j - 1];
					idx[i][j] = idx[i][j - 1];
				}
				else {
					if (idx[i][j - 1] == 0) {
						if (nums[j] - nums[j - 1] > 0) {
							dp[i][j] = dp[i][j - 1] + 1;
							idx[i][j] = 1;
						}
						else {
							dp[i][j] = dp[i][j - 1] + 1;
							idx[i][j] = 2;
						}
					}
					else {
						if (nums[j] - nums[j - 1] > 0) {
							dp[i][j] = dp[i][j - 1];
							idx[i][j] = 1;
						}
						else {
							dp[i][j] = dp[i][j - 1];
							idx[i][j] = 2;
						}
					}
				}
			}
		}
	}
	/*for (int i = 0; i < numsSz; i++) {
		for (int j = 0; j < numsSz; j++) {
			cout << dp[i][j] << " "<<idx[i][j]<<" ";
		}
		cout << endl;
	}*/
	return dp[0][numsSz - 1];
}
};


//但是我们用贪心思路我们不需要求每个区间的摇摆序列的个数我们只需要求开始到当前位置的摇摆序列个数即可：
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int  numsSz = nums.size();
		if (numsSz < 2) return numsSz;
		int res = 1;
		int idx = 0;
		for (int i = 1; i < numsSz; i++) {
			if (nums[i] - nums[i - 1] > 0) {
				if (idx != 1) {
					res++;
					idx = 1;
				}
			}
			if (nums[i] - nums[i - 1] < 0) {
				if (idx != 2) {
					res++;
					idx = 2;
				}
			}
		}
		return res;
	}
};
