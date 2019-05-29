/**本题需要动态的进行查找，删除以及找中位数的操作 而如果正常的数据结构 比如map 数组等 在删除或者查找的时间复杂度都是O(N)的时间复杂度所以我们需要用一个灵活的方式进行数据结构的选择
* 在leetcode有道题是利用大小堆来动态的生成中位数利用这个思路我们可以设计一个巧妙地数据结构：
* 我们维护两个map数组 左map递减右map递增 而且我们要求左map的最大值始终小于右map的最小值 而且左map的元素个数始终等于或者比右map大1 这样下来我们的几个操作：
* 删除(pop)也就是在左map或者右map中删除一个数最多再进行一次调整即可 map底层实现是红黑树所以也就为O(log(N))
* 插入(push)也就是插入一个数同样最多再进行一次调整即可 时间复杂度也是O(log(N))
* 求中位数(peek) 对于中位数很容易得到，左map的第一个数也就是中位数 所以时间复杂度也就是O(1)**/

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main() {
	int num;
	cin >> num;
	stack<int> stk;
	map<int, int>  rbt2;
	map<int, int, greater<int>> rbt1;
	int lt = 0, rt = 0;
	for (int i = 0; i < num; i++) {
		char str[10];
		scanf("%s", &str);
		if (str[1] == 'o') {
			if (stk.empty()) {
				printf("Invalid\n");
			}
			else {
				int tmp = stk.top();
				stk.pop();
				if (rbt1.find(tmp) != rbt1.end()) {
					if (lt > rt) {
						rbt1[tmp]--;
						if (rbt1[tmp] == 0)
							rbt1.erase(tmp);
						lt--;
					}
					else if (lt == rt) {
						rbt1[tmp]--;
						if (rbt1[tmp] == 0)
							rbt1.erase(tmp);
						int tmpi = (*rbt2.begin()).first;
						rbt2[tmpi]--;
						if (rbt2[tmpi] == 0) {
							rbt2.erase(tmpi);
						}
						rbt1[tmpi]++;
						rt--;
					}
				}
				else {
					if (rt == lt) {
						rbt2[tmp]--;
						if (rbt2[tmp] == 0)
							rbt2.erase(tmp);
						rt--;
					}
					else {
						rbt2[tmp]--;
						if (rbt2[tmp] == 0)
							rbt2.erase(tmp);
						int tmpi= (*rbt1.begin()).first;
						rbt1[tmpi]--;
						if (rbt1[tmpi] == 0)
							rbt1.erase(tmpi);
						rbt2[tmpi]++;
						lt--;
					}
				}
				printf("%d\n", tmp);
			}
		}
		else if (str[1] == 'u') {
			int tmp;
			scanf("%d", &tmp);
			stk.push(tmp);
			if (lt == rt) {
				if (lt == 0) {		
					rbt1[tmp]++;
				}
				else {
					if (tmp <= (*rbt2.begin()).first) {
						rbt1[tmp]++;
					}
					else {
						int tmpi = (*rbt2.begin()).first;
						rbt2[tmpi]--;
						if (rbt2[tmpi] == 0) {
							rbt2.erase(tmpi);
						}
						rbt2[tmp]++;
						rbt1[tmpi]++;
					}
				}
				lt++;
			}
			else if (lt > rt) {
				if (tmp<=(*rbt1.begin()).first) {
					int tmpi = (*rbt1.begin()).first;
					rbt1[tmpi]--;
					if (rbt1[tmpi] == 0)
						rbt1.erase(tmpi);
					rbt1[tmp]++;
					rbt2[tmpi]++;
				}
				else {
					rbt2[tmp]++;
				}
				rt++;
			}
		}
		else if (str[1] == 'e') {
			if (stk.empty()) {
				printf("Invalid\n");
			}
			else {
				int tmp = (*rbt1.begin()).first;
				//cout << tmp << endl;
				printf("%d\n", tmp);
			}
		}
	}

}
