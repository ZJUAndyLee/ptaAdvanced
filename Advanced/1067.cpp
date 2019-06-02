//贪心算法 每次都让0所在的点到达正确的位置，然后如果0回到了位置0这时我们需要去遍历数组找到 位置不正确的点 但是这样太浪费时间 所以我们可以重新建一个表来记录所有位置不正确的点每次都去里面找位置不正确的点就可以了

#include <vector>
#include<algorithm>
#include<unordered_set>
#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> vec(num, 0);
	vector<int> arr(num, 0);
	unordered_set<int> hs;
	int idx = 0;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d",&tmp);
		if (tmp != i) {
			hs.insert(tmp);
		}
		if (tmp == 0) {
			idx = i;
		}
		vec[i] = tmp;
		arr[tmp] = i;
	}
	int res = 0;
	hs.erase(0);
	while (!hs.empty()) {
		if (idx != 0) {
			vec[idx] = idx;
			hs.erase(idx);
			vec[arr[idx]] = 0;
			idx = arr[idx];
			res++;
		}
		else {
			int tmp = *(hs.begin());
			vec[arr[tmp]] = 0;
			vec[0] = tmp;
			idx = arr[tmp];
			arr[tmp] = 0;
			res++;
		}
	}
	cout << res << endl;

}
