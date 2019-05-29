#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


int main() {
	int num, gp;
	cin >> num >> gp;
	vector<int> w;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		w.push_back(tmp);
	}
	vector<int> q;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		q.push_back(tmp);
	}

	vector<int> res(num, 0);
	while(q.size()>1) {
		int sz = q.size();
		int ct = sz % gp == 0 ? sz / gp : sz / gp + 1;//计算出当前胜出的人数 而本轮的输的人的名次也就为胜出的人的个数+1
		vector<int> next;
		int idx = 0;
		while (idx < sz) {
			pair<int, int> pmax(-1, -1);
			for (int j = 0; j < gp; j++) {//得到每一组的胜出者
				if (w[q[idx]] > pmax.first) {
					if (pmax.second != -1)
						res[pmax.second] = ct + 1;
					pmax.first = w[q[idx]];
					pmax.second = q[idx];
				}
				else {
					res[q[idx]] = ct + 1;
				}
				idx++;
				if (idx >= sz)
					break;
			}
			next.push_back(pmax.second);//每组的胜出者重新进入比赛队列进行比赛
		}
		q = next;
	}
	res[q[0]] = 1;
	for (int i = 0; i < num; i++) {
		if (!i)
			cout << res[i];
		else
			cout << " " << res[i];
	}

}
