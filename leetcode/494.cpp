//这个题直接暴力递归是O(2的N次方)太慢 所以我改进了一下 反向查询减去某个或者某几个数是不是匹配 当时由于数列中有零所以还需要额外考虑一些情况：
  int res, s,ct;
void dfs(vector<int>&n, int iter, int sum) {
	if (sum - 2 * n[iter]<s) return;
	if (sum - 2 * n[iter] == s) {
		res++;
		int tmp = 0;
		for (int i = iter + 1; i < n.size(); i++) {//当满足条件时不能直接返回而是要判断是否后面有零！！
			if (n[i] == 0)
				tmp++;
		}
		res += pow(2, tmp)-1;
		return;
	}
	sum -= 2 * n[iter];
	for (++iter; iter<n.size(); iter++) {
		dfs(n, iter, sum);
	}
}

int findTargetSumWays(vector<int>& nums, int S) {
	res = 0;
	s = S;
	if (nums.size()<1) return res;
	int sum = 0;
	for (int i = 0; i<nums.size(); i++) {
		sum += nums[i];
	}
	if (sum == S) res++;
	if (sum<S) return 0;
	for (int i = 0; i<nums.size(); i++) {
		dfs(nums, i, sum);
	}
	return res;
}

//优解如下：
// 我们可以把本题看成一个正子集减去负子集的操作有： sum(P)-sum(N) = target => sum(P)-sum(N)+ sum(P)+sum(N) = target + sum => 2*sum(P) = target + sum
//所以本题转化为求子集和：
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //vector<vector<int>> vvi()
        long long sums = S;
        for(auto& num:nums)sums+=num;
        if(sums%2!=0)return 0;
        if(sums<2*S)return 0;
        int target = sums / 2;
        
        vector<int> vi(target+1, 0);
        vi[0]=1;
        for(auto& num:nums){
            for(int i = target; i != num - 1 && i - num >= 0; --i){//其中这个地方用动态规划来记录我们的目标和到0的所有有可能的子集和的可能的情况的数目 这样我们就可以轻松得出我们的目标子集和的个数
                vi[i] += vi[i-num];
            }
        }
        return vi[target];
    }
};
