//其实这就是一道在线处理的题目 有点像最大子列和的问题 计算出每个站能剩下多少油 然后把剩下的油累加起来 必须满足累加和大于零否则重新累加 因为只有大于等于零
//才能说明 能够前往下一站。否则 我们出发站则为当前累加的下一站
//最后 我们只需要判断累加和是否大于零 如果大于零说明能循环否则说明不能

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int tmp;
	vector<int> tmp1, tmp2, tmp3;
	int sz = gas.size();
	for (int i = 0; i < sz ; i++) {
		tmp1.push_back(gas[i] - cost[i]);
		
	}
	tmp = 0;
	for (int i = 0; i < sz; i++) {
		tmp += tmp1[i];
		tmp2.push_back(tmp);
	}

	if (tmp2.back() < 0)return -1;
	
	
	for (int i = 0; i < sz; i++) {
		if (tmp1[i] >= 0) {
			int sum = 0;
			int j = i;
			for (j = i; j < sz; j++) {
				sum += tmp1[j];
				if (sum < 0) {
					i = j;
					break;
				}
			}
			if (j == sz) {
				if (i > 0) {
					if (sum + tmp2[i - 1] >= 0) return i;
				}
				else {
					if (sum >= 0) return i;
				}
			}
		}
	}
	return -1;
}
