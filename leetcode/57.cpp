//插入区间其实可以用合并区间那道题直接去做 但是其实这道题不难分情况讨论然后每个点都搞清楚就可以了

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int i = 0, sz = intervals.size();
		vector<Interval> res;
		if (sz == 0) { res.push_back(newInterval); return res; }
		if (newInterval.end < intervals[0].start) {
			res.push_back(newInterval);
			res.insert(res.end(), intervals.begin(), intervals.end());
			return res;
		}
		if (newInterval.start > intervals.back().end) {
			intervals.push_back(newInterval);
			return intervals;
		}
		while (i < sz) {
			if (intervals[i].end < newInterval.start) { res.push_back(intervals[i]); i++; }
			else if (intervals[i].start > newInterval.end) {
				res.push_back(newInterval);
				while (i < sz) {
					res.push_back(intervals[i]); i++;
				}
			}
			else {
				newInterval.start = min(intervals[i].start, newInterval.start);
				newInterval.end = max(intervals[i].end, newInterval.end);
				i++;
				if (i == sz) res.push_back(newInterval);
				while (i < sz) {
					if (newInterval.end >= intervals[i].start) {
						newInterval.end = max(newInterval.end, intervals[i].end);
						i++;
						if (i == sz) res.push_back(newInterval);
					}
					else {
						res.push_back(newInterval);
						while (i < sz) {
							res.push_back(intervals[i]); i++;
						}
					}
				}
			}
		}
		return res;
	}
};
