//这个题有个大坑点就是当LIst为0的时候 你也要写一个-1 的指针

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int num,first;
struct node {
	int key;
	int next;
	node(int x, int y) :key(x), next(y) { };
	node() {};
};
unordered_map<int,node> mp;
void Input() {
	cin >> num >> first;
	for (int i = 0; i < num; i++) {
		int tmp1, tmp2, tmp3;
		scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
		mp[tmp1] = node(tmp2, tmp3);
	}
}

bool cmp(node &p1,node &p2) {
	return p1.key > p2.key ? false : true;
}

void LinkedListSorting() {
	int tmp = first;
	vector<node> res;
	while (tmp > 0) {
		if (mp.find(tmp) != mp.end()) {
			res.push_back(node(mp[tmp].key, tmp));
			tmp = mp[tmp].next;
		}
		else {
			break;
		}
	}
	sort(res.begin(), res.end(), cmp);
	if (res.empty()) {
		cout << 0<<" "<<-1;
		return;
	}
	int sz = res.size();
	printf("%d %05d\n", sz, res[0].next);
	for (int i = 0; i < sz - 1; i++) {
		printf("%05d %d %05d\n", res[i].next,res[i].key, res[i+1].next);
	}
	printf("%05d %d %d\n", res.back().next, res.back().key, -1);
}

int main() {
	Input();
	LinkedListSorting();

}
