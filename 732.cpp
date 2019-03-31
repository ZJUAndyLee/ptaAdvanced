//这个题就是上个题的升级版 区间正负划分排序处理这个思路可以说是非常聪明的一个思路，而底层的数据结构就是AVL或者RBT

class MyCalendarThree {
public:
	MyCalendarThree():max(-1) {

	}

	int book(int start, int end) {
		rbt[start]++;
		rbt[end]--;
		int ct = 0, tmp = -1;
		for (map<int, int>::iterator iter = rbt.begin(); iter != rbt.end(); iter++) {
			if (iter->first < end) {
				ct += iter->second;
				tmp = ct > tmp ? ct : tmp;//这里需要注意 有些区间跨越多个区间 你必须找到重合的最大区间
			}
			else break;
		}
		max = max > tmp ? max : tmp;
		return max;
	}
	map<int, int> rbt;
	int max;
};
