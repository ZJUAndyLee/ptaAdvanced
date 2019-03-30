//区间插入 或者说线段插入的问题 最最最重要的一个很方便的算法就是将区间排序 然后每一个区间的左端可以标记为正的区间的右端可以标记为负的
//类似于城市天际线那道题假设区间还有一个高度的因素话就将高度作为另一个维度记录

class MyCalendarTwo {
public:
	MyCalendarTwo(){}

	bool book(int start, int end) {
		rbt[start]++;
		rbt[end]--;
		int ct = 0;
		for (map<int, int>::iterator iter = rbt.begin(); iter != rbt.end(); iter++) {
			ct += iter->second;
			if (ct >= 3) {
				rbt[start]--;
				rbt[end]++;
				return false;
			}
		}
		return true;
	}
	map<int, int> rbt;
};
