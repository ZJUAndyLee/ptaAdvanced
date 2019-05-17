//多权值dijstra算法
#include<iostream>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

#define IMAX 10000000

int Num, Edge,st,dt;
vector<unordered_map<int, pair<int, int>>> g;

void Input() {
	cin >> Num >> Edge >> st >> dt;
	g.assign(Num, unordered_map<int, pair<int, int>>());
	for (int i = 0; i < Edge; i++) {
		int v1, v2, dis, cos;
		cin >> v1 >> v2 >> dis >> cos;
		g[v1][v2] = pair<int, int>(dis, cos);
		g[v2][v1] = pair<int, int>(dis, cos);
	}
}

void TravelPlan() {
	vector<int> dis(Num, IMAX), cost(Num, IMAX), path(Num, 0), vis(Num, 0);
	dis[st] = 0; 
	cost[st] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qe;
	qe.push(pair<int,int>(0, st));
	while(!qe.empty()) {//dijstra 算法的精髓就是 把所有点分成两类 一类是最短路径点 一类是待探索的点 而每次从待探索的点中拿出离原点最近的点也必为最短路径 然后再对该店进行边的松弛
		pair<int,int> tmpe = qe.top();
		qe.pop();
		if (vis[tmpe.second])
			continue;
		vis[tmpe.second] = 1;
		for(auto x:g[tmpe.second]){
			if (dis[x.first] > dis[tmpe.second] + x.second.first) {
					path[x.first] = tmpe.second;
					dis[x.first] = dis[tmpe.second] + x.second.first;
					cost[x.first] = cost[tmpe.second] + x.second.second;
					qe.push(pair<int, int>(dis[x.first], x.first));
			}
			else if (dis[x.first] == dis[tmpe.second] + x.second.first) {
				int tmp = cost[tmpe.second] + x.second.second;
				if (tmp < cost[x.first]) {
					cost[x.first] = tmp;
					path[x.first] = tmpe.second;
				}
			}
		}
	}
	int ii = dt;
	stack<int> stk;
	while (ii != st) {
		stk.push(ii);
		ii = path[ii];
	}
	int resd=0, resc=0, iter = st;
	cout << st;
	while (!stk.empty()) {
		int tmp = stk.top();
		stk.pop();
		cout << " " << tmp;
		iter = tmp;
	}
	cout << " " << dis[dt] << " " << cost[dt];
}

int main() {
	Input();
	TravelPlan();

}
