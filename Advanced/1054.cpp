//求众数

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

unordered_map<int, int> hs;
bool cmp(pair<int, int> &p1, pair<int, int>&p2) {
	return p1.second > p2.second ? true : false;
}
int main() {
	int col, row;
	cin >> col >> row;
	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			int tmp;
			scanf("%d",&tmp);
			hs[tmp]++;
		}
	}
	vector<pair<int,int>> res;
	for (auto x : hs) {
		res.push_back(x);
	}
	sort(res.begin(), res.end(), cmp);
	cout << res[0].first;

}
