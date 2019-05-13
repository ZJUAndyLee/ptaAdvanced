#include<vector>
#include<iostream>
#include<iomanip>
#include<string>
#include<queue>
#include<algorithm>
#include<stdio.h>
using namespace std;
//优先队列加排序 直接用秒去解决问题不要引入浮点数 逻辑思维要清晰
int N, M;

struct cms {
	int cm, p;
	cms(int come, int pt) :cm(come), p(pt) {};
};

bool cmp(cms &c1, cms &c2) {
	return c1.cm > c2.cm ? false : true;
}

void Input(vector<cms> &v) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int hr, min, sec, time;
		scanf("%d:%d:%d %d", &hr, &min, &sec, &time);
		int tts = hr * 3600 + min * 60 + sec;
		if (tts > 61200)
			continue;
		v.push_back(cms(tts, time * 60));
	}
}

void QueueingAtBank(vector<cms> &cost) {
	if (cost.size() < 1) {
		cout << 0.0 << endl;
		return;
	}
	sort(cost.begin(), cost.end(), cmp);
	int res=0;
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i = 0; i < M; i++) {
		q.push(0);
	}
	for (int i = 0; i < cost.size(); i++) {
		int tmpI = q.top();
		q.pop();
		//tmpI = tmpI > 32400 ? 32400 : tmpI; 加了这句就不对不知道为啥 
		if (cost[i].cm < 28800) {
            res += 28800 - cost[i].cm;
			if (tmpI > 0)
				res += tmpI;
			q.push(cost[i].p + tmpI);
		}
		else {
			int tmpI1 = cost[i].cm - 28800;
			if (tmpI > tmpI1) {
                res += tmpI - tmpI1;
				q.push(tmpI + cost[i].p);
			}
			else {
				q.push(tmpI1 + cost[i].p);
			}
		}
	}
	cout << fixed << setprecision(1) << res / (60.0*cost.size()) << endl;
}

int main() {
	vector<cms> vec;
	Input(vec);
	QueueingAtBank(vec);

}
