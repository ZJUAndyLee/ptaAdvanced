//hash表思路 最后判断的时候遍历数组直接用set的find进行操作不要再insert了
//输入的时候我们就用一个哈希表来代替vector从而直接消除同一个组中的相同的数的干扰 提高效率

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;


vector<unordered_set<int>> query;
vector<pair<int, int>> pr;

void Input() {
	int num;
	scanf("%d", &num);
	query.assign(num, unordered_set<int>());
	for (int i = 0; i < num; i++) {
		int tmpnum;
		scanf("%d", &tmpnum);
		for (int j = 0; j < tmpnum; j++) {
			int tmp;
			scanf("%d", &tmp);
			query[i].insert(tmp);
		}
	}
	int pnum;
	scanf("%d", &pnum);
	for (int i = 0; i < pnum; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		pr.push_back(pair<int, int>(x, y));
	}
}


void SetSimilarity() {
	for (auto x : pr) {
		unordered_set<int> mp;
		int ct = 0, tt = 0;
		for (int y : query[x.first - 1]) {
			if(mp.find(y)==mp.end())
				tt++;
			mp.insert(y);
		}
		for (int y : query[x.second - 1]) {
			if (mp.find(y) != mp.end())
				ct++;
			else
				tt++;
		}
		double res = ct * 100.0/ tt;
		printf("%.1f%%\n",res);
	}
}

int main() {
	Input();
	SetSimilarity();


}

