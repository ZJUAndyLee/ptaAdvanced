//用hash表做链表，注意可能有多条链表或者有断点 我们需要将我们要处理的链表给找出来

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int head, num, idx;
unordered_map<int, pair<int,int>> List1;


void Input() {
	scanf("%d %d %d", &head, &num, &idx);
	int flag = 1;
	for (int i = 0; i < num; i++) {
		int hd, val, nt;
		scanf("%d %d %d", &hd, &val, &nt);
		List1[hd] = pair<int, int>(nt, val);
	}
}

void ReversingLinkedList() {
	unordered_map<int, pair<int, int>> res;
	unordered_map<int, pair<int, int>> List;
	int flag = head, ct = 0;
	while (flag >= 0) {
		List[flag] = List1[flag];
		flag = List1[flag].first;
		ct++;
	}
	int tms = ct / idx;
	int tmph = head, ltfirst = head, first = head;
	for (int i = 0; i < tms; i++) {
		first = tmph;
		for (int j = 0; j < idx; j++) {
			if (j == idx - 1) {
				if (i > 0) {
					res[ltfirst] = pair<int, int>(tmph, List[ltfirst].second);
					ltfirst = first;
				}
				else{
					head = tmph;
				}
			}
			else {
				res[List[tmph].first] = pair<int, int>(tmph, List[List[tmph].first].second);
				
			}
			tmph = List[tmph].first;
		}
	}
	res[first].second = List[first].second;
	res[first].first = tmph;
	while(tmph >= 0) {
		
		res[tmph] = List[tmph];
		tmph = List[tmph].first;
		
	}
	while (head >= 0) {
		if (res[head].first >= 0) {
			printf("%05d %d %05d\n", head, res[head].second, res[head].first);
		}
		else {
			printf("%05d %d %d\n", head, res[head].second, -1);
		}
		head = res[head].first;
	}
}
int main() {
	
	Input();
	ReversingLinkedList();
	//system("pause");
}

