//优先队列加维护一个和窗口数一样的大小的双端队列 最后每次进队的时候就可以确定每个点的时间

#include<vector>
#include<iostream>
#include<iomanip>
#include<queue>
#include<unordered_map>
using namespace std;

int N, M, K, Q;

struct cus {
	int t, num, q;
	cus(int x, int y, int z) :t(x), num(y), q(z) {};
};
struct cmp {
	bool operator()(cus &p1,cus &p2) {
		if (p1.t > p2.t) return true;
		else if (p1.t == p2.t) {
			if (p1.q > p2.q)
				return true;
		}
		return false;
	}
};

void Input(vector<int> &tm,vector<int> &ck) {
	cin >> N >> M >> K >> Q;
	tm.push_back(0);
	for (int i = 1; i <= K; i++) {
		int tmp;
		cin >> tmp;
		tm.push_back(tmp);
	}
	for (int i = 0; i < Q; i++) {
		int tmp;
		cin >> tmp;
		ck.push_back(tmp);
	}
}

void WaitingInLine(vector<int> &tm, vector<int> &ck) {
	vector<deque<pair<int, int>>> que(N + 1, deque<pair<int, int>>());
	vector<int> res(K + 1, 0);
	for (int j = 0; j < M; j++) {
		for (int i = 1; i <= N; i++) {
			if (j*N + i <= K) {
				if (j == 0) {
					que[i].push_back(pair<int, int>(tm[i], j*N + i));
					res[j*N + i] = tm[i];
				}
				else {
					int tmpI = tm[j*N + i] + que[i].back().first;
					if (que[i].back().first < 540) {
						res[j*N + i] = tmpI;
					}
					que[i].push_back(pair<int, int>(tmpI, j*N + i));
				}
			}
			else
				break;
		}
	}
	priority_queue<cus, vector<cus>, cmp> minHeap;
	
	
	if (N*M < K) {
		for (int j = 1; j <= N; j++) {
			if (!que[j].empty()) {
				pair<int, int> tmp = que[j].front();
				if (tmp.first > 540) continue;
				cus tmpc(tmp.first, tmp.second, j);
				minHeap.push(tmpc);
			}
		}
		for (int i = N * M + 1; i <= K; i++) {
			cus tmpc = minHeap.top();
			minHeap.pop();
			int tmpI = que[tmpc.q].back().first + tm[i];
			if (que[tmpc.q].back().first < 540) {
				res[i] = tmpI;
			}
			que[tmpc.q].push_back(pair<int, int>(tmpI, i));
			
			que[tmpc.q].pop_front();
			pair<int, int> tmp = que[tmpc.q].front();
			minHeap.push(cus(tmp.first, tmp.second, tmpc.q));
		}
	}
	for (int i = 0; i < Q; i++) {
		if (!res[ck[i]])
			cout << "Sorry" << endl;
		else {
			int h = res[ck[i]] / 60 + 8;
			int m = res[ck[i]] % 60;
			if (h < 10) {
				cout << 0 << h << ":";
			}
			else {
				cout << h << ":";
			}
			if (m < 10) {
				cout << 0 << m << endl;
			}
			else {
				cout << m << endl;
			}
		}
	}
}


int main() {
	vector<int> N1, N2;
	Input(N1, N2);
	WaitingInLine(N1, N2);
	

}
