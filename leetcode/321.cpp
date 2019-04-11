//拼接最大数 首先我们分别在两个不同的数组里找到最大的带拼接的数 然后再将两个最大拼接数组合并
//而比较关键的地方就是在于我们如果找到单个数组的最大拼接数，这就使用到了贪心思路 我们必须使每一位数都必须是指定范围最大的 
//制定的范围就是前一个数的后面以及最后不能少于总长的这么一个区间之间
class Solution {
public:
vector<int> cmpVec(vector<int>&v1,vector<int>&v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] > v2[i]) return v1;
		else if (v1[i] < v2[i]) return v2;
	}
	return v1;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<pair<int, int>> vec1, vec2;
	int sz1 = nums1.size(), sz2 = nums2.size();
	for (int i = 0; i < sz1; i++) {
		vec1.push_back(pair<int, int>(nums1[i], i));
	}
	for (int j = 0; j < sz2; j++) {
		vec2.push_back(pair<int, int>(nums2[j], j));
	}
	vector<int> res(k, -1);
	for (int i = 0; i <= k; i++) {
		int j = k - i;
		if (i <= sz1 && j <= sz2) {
			deque<int> tmpMax1, tmpMax2;
			vector<int> tmpMax;
			int idx1 = -1, idx2 = -1;
			
			for (int iter = 0; iter < i; iter++) {
				pair<int, int> tmpp(-1,0) ;
				for (int ii = idx1 + 1; ii < sz1 - (i-iter-1); ii++) {
					if (nums1[ii] > tmpp.first) {
						tmpp.first = nums1[ii];
						tmpp.second = ii;
						
					}
				}
				tmpMax1.push_back(tmpp.first);
				idx1 = tmpp.second;
			}
			for (int iter = 0; iter < j; iter++) {
				pair<int, int> tmpp(-1, 0);
				for (int ii = idx2 + 1; ii < sz2 - (j - iter - 1); ii++) {
					if (nums2[ii] > tmpp.first) {
						tmpp.first = nums2[ii];
						tmpp.second = ii;
					}
				}
				tmpMax2.push_back(tmpp.first);
				idx2 = tmpp.second;
			}
			
			while (!tmpMax1.empty() && !tmpMax2.empty()) {
				if (tmpMax1 > tmpMax2) {
					tmpMax.push_back(tmpMax1.front());
					tmpMax1.pop_front();
				}
				else {
					tmpMax.push_back(tmpMax2.front());
					tmpMax2.pop_front();
				}
			}
			
			while (!tmpMax1.empty()) {
				tmpMax.push_back(tmpMax1.front());
				tmpMax1.pop_front();
			}
			while (!tmpMax2.empty()) {
				tmpMax.push_back(tmpMax2.front());
				tmpMax2.pop_front();
			}
			res = cmpVec(res, tmpMax);
		}

	}
	return res;
}

};
