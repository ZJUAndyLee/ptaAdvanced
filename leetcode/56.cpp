//这个题只需要把每个区间的左端点排序然后再一个区间一个区间的进行比较合并即可

struct cmp {
	bool operator()(Interval &p1,Interval &p2) {
		return p1.start > p2.start ? true : false;
	}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), cmp());
		Interval tmp = intervals[0];
		vector<Interval> res;
		for (int i = 1; i < intervals.size(); i++) {
			if (tmp.end < intervals[i].start) {
				res.push_back(tmp);
				tmp = intervals[i];
			}
			else {
				tmp.end = max(tmp.end, intervals[i].end);
			}
		}
		res.push_back(tmp);
		return res;
	}
};
