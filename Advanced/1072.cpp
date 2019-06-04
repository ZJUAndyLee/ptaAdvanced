//dijkstra算法 然后相关参数进行比较 最后一个点超时

#include <vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

#define MaxI 100000000
int N, M, K, Ds;

vector<vector<pair<int, int>>> g;

void Input() {
	cin >> N >> M >> K >> Ds;
	g.assign(N + M + 1, vector<pair<int, int>>());
	for (int i = 0; i < K; i++) {
		char ch1[4], ch2[4];
		int ds;
		scanf("%s %s %d", &ch1, &ch2, &ds);
		int s1 = 0, s2 = 0;
		if (isdigit(ch1[0]))
			s1 = atoi(ch1) + M;
		else if(ch1[2]=='0'){
			s1 = 10;
		}
		else {
			s1 = ch1[1] - '0';
		}
		if (isdigit(ch2[0]))
			s2 = atoi(ch2) + M;
		else {
			s2 = ch2[1] - '0';
		}
		g[s1].push_back(pair<int, int>(ds, s2));
		g[s2].push_back(pair<int, int>(ds, s1));
	}
}


void Dijkstra(vector<int> &dis,int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> vis(N + M + 1, 0);
	vis[st] = 1;
	for (auto x : g[st]) {
		q.push(pair<int, int>(x));
		dis[x.second] = x.first;
	}
	while (!q.empty()) {
		pair<int, int>tmpp = q.top();
		q.pop();
		vis[tmpp.second] = 1;
		for (auto x : g[tmpp.second]) {
			if (vis[x.second] == 0) {
				if (dis[x.second] > dis[tmpp.second] + x.first) {
					dis[x.second] = dis[tmpp.second] + x.first;
				}
				q.push(pair<int, int>(x));
			}
		}
	}
}

void GasStation() {
	pair<int, pair<int, int>> res(0,pair<int,int>(0,MaxI));
	for (int i = 1; i <= M; i++) {
		vector<int> dis(N + M + 1, MaxI);
		dis[i] = 0;
		Dijkstra(dis, i);
		int minds = MaxI, idx = 1;
		int total = 0;
		/*if (i == 1) {
			for (int k = 1; k < N + M + 1; k++) {
				cout << k << " " << dis[k] << endl;
			}
		}*/
		for (int j = M + 1; j <= M + N; j++) {
			if (dis[j] > Ds) {
				idx = 0;
				break;
			}
			minds = min(minds, dis[j]);
			total += dis[j];
		}
		
		if (idx) {
			if (minds > res.second.first) {
				res.first = i;
				res.second.first = minds;
				res.second.second = total;
			}
			else if (minds == res.second.first) {
				if (total < res.second.second) {
					res.first = i;
					res.second.first = minds;
					res.second.second = total;
				}
			}
		}
	}
	if (res.first == 0) {
		printf("No Solution\n");
		return;
	}
	printf("G%d\n", res.first);
	printf("%.1f %.1f", res.second.first / 1.0, res.second.second / (N*1.0));
}

int main() {
	Input();
	GasStation();
	

}
