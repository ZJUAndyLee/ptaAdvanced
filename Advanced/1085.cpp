//两点需要注意 1. 利用二分查找提高算法效率， 2. 注意两数相乘可能会超过int的范围需要用long long

#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int BinarySearch(vector<pair<int,int>>&v,int tar) {
	int st = 0, ed = v.size() - 1, mid = (st + ed) / 2;
	while (st < ed) {
		if (v[mid].first == tar)
			return mid;
		else if (v[mid].first < tar) {
			st = mid+1;
		}
		else {
			ed = mid;
		}
		mid = (st + ed) / 2;
	}
	return st;
}

int main() {
	int num, p;
	scanf("%d %d", &num, &p);
	unordered_map<int, int> hs;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		hs[tmp]++;
	}
	vector<pair<int, int>> vec(hs.begin(), hs.end());
	sort(vec.begin(), vec.end());
	int total = 0;
	for (int i = 0; i < vec.size(); i++) {
		total += vec[i].second;
		vec[i].second = total;
	}
	int res = 0;
	for (int i = 0; i < vec.size(); i++) {
		long long M =  (long long)( vec[i].first)*(long long)(p);
		if (M <= vec.back().first) {
			int idx = BinarySearch(vec, M);
			if (vec[idx].first == M) {
				res = max(res, vec[idx].second - vec[i].second + hs[vec[i].first]);
			}
			else {
				res = max(res, vec[idx].second - vec[i].second + hs[vec[i].first] - hs[vec[idx].first]);
			}
		}
		else {
			res = max(res, num - vec[i].second + hs[vec[i].first]);
			break;
		}
	}
	cout << res;

}
