//这道题自己的想法直接超时 看了一下 这个算法这个很漂亮有一个有点点小bug的地方我进行了调整 我自己超时的算法我就不贴了

int oddEvenJumps(vector<int>& A) {
	int sz = A.size();
	map<int, int> rbt;
	vector<pair<bool, bool>> label(sz, pair<bool, bool>(0, 0));//标记奇跳与偶跳
	label[sz - 1].first = 1; label[sz - 1].second = 1;//数组最后一个无论奇跳还是偶跳都是对的
	rbt[A[sz - 1]] = sz - 1;//把红黑树初始化 第一个值就是最后一个元素
	int res = 1;
	for (int i = sz - 2; i >= 0; i--) {
		auto iter = rbt.lower_bound(A[i]);//这就相当于一次奇跳
		if (iter != rbt.end() && label[iter->second].second) {//如果奇跳之后的那个点的偶跳是true的话说明这个点是一个奇跳正确点
			res++;
			label[i].first = 1;
		}
		if (((iter!=rbt.end()&&iter->first == A[i] && label[iter->second].first) || (iter != rbt.begin() && label[(--iter)->second].first))) {
			//上个判断完该点是奇跳之后 我们还要继续判断当前点是不是偶跳点
			//是偶跳点有几种情况 假设我们找到的数等于当前这个数 那么说明当前这个数的偶跳之后就是iter所以我只要判断iter是不是奇跳点就行了
			//其次 如果当前数比数组后面已经遍历过的数都要小 那么就说明这个点不可能是偶跳点
			//再者 我们就判断当前找到的这个数在红黑树的上一位的这个数 也就是小于A[i] 但是位于A[i]后面的这个数 是不是一个奇跳点就行了
			label[i].second = 1;
		}
		rbt[A[i]] = i;
	}
	return res;
