//贪心策略按奇偶进行寻找 一定要使情侣数在当前数的后一位
//首先用一个数组把原始的每一位数的位置信息存下来 然后在后面交换的时候记得交换他们的位置信息即可
class Solution {
public:
   int minSwapsCouples(vector<int>& row) {
	int N = row.size();
	int *hash = new int[N];
	for (int i = 0; i < N; i++) {
		hash[row[i]] = i;
	}
	int res = 0;
	for (int i = 0; i < N; i = i + 2) {
		if (row[i] % 2) {
			if (hash[row[i]-1] != i + 1) {
				hash[row[i + 1]] = hash[row[i] - 1];
				swap(row[i + 1], row[hash[row[i] - 1]]);
				hash[row[i] - 1] = i + 1;
				res++;
			}
		}
		else {
			if (hash[row[i] + 1] != i + 1) {
				hash[row[i + 1]] = hash[row[i] + 1];
				swap(row[i + 1], row[hash[row[i] + 1]]);
				hash[row[i] + 1] = i + 1;
				res++;
			}
		}
	}
	return res;
}
};
