//dijkstra+DFS 有个点没过

#include <iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
#define Imax 2147483647;
unordered_map<string, vector<string>> path;
vector<pair<int, vector<string>>> res;
void Dijkstra(unordered_map<string, vector<pair<string, int>>>&mp, unordered_map<string, int>&cost,unordered_map<string,int>&vis,string root) {
	priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> qu;
	qu.push(pair<int, pair<string, string>>(0, pair<string, string>(root, root)));
	while (!qu.empty()) {
		pair<int, pair<string, string>> tmp = qu.top();
		qu.pop();
		if (cost[tmp.second.second] > cost[tmp.second.first] + tmp.first) {
			cost[tmp.second.second] = cost[tmp.second.first] + tmp.first;
			path[tmp.second.second].clear();
			path[tmp.second.second].push_back(tmp.second.first);
		}
		else if (cost[tmp.second.second] == cost[tmp.second.first] + tmp.first) {
			path[tmp.second.second].push_back(tmp.second.first);

		}
		vis[tmp.second.first] = 1;
		if (tmp.second.second != "ROM") {
			for (auto x : mp[tmp.second.second]) {
				if (vis[x.first] != 1) {
					qu.push(pair<int, pair<string, string>>(x.second, pair<string, string>(tmp.second.second, x.first)));
				}
			}
		}
	}
}

void dfs(unordered_map<string, int>&hp,int &numroot,string st,string pos,int total,vector<string> pt) {
	total = total + hp[pos];
	pt.push_back(pos);
	for (auto x : path[pos]) {
		if (x != st) {
			dfs(hp, numroot, st, x, total,pt);
		}
		else {
			numroot++;
			pt.push_back(x);
			res.push_back(pair<int, vector<string>>(total, pt));
			return;
		}
	}
}

bool cmp(pair<int, vector<string>>&p1, pair<int, vector<string>>&p2) {
	if (p1.first > p2.first)
		return true;
	else if (p1.first == p2.first) {
		if (p1.second.size() < p2.second.size())
			return true;
		else
			return false;
	}
	return false;
}

int main() {
	unordered_map<string, vector<pair<string,int>>> mp;
	unordered_map<string, int> cost;
	unordered_map<string, int> hp;
	unordered_map<string, int> vis;
	string st;
	int N, K;
	cin >> N >> K >> st;
	cost[st] = 0;
	for (int i = 1; i < N; i++) {
		char c[4];
		int tmp;
		scanf("%s %d", &c, &tmp);
		string ch = c;
		hp[ch] = tmp;
		cost[ch] = Imax;
		vis[ch] = 0;
	}
	for (int i = 0; i < K; i++) {
		char s[4], e[4];
		int tmp;
		scanf("%s %s %d", &s, &e, &tmp);
		string ed = e, st = s;
		mp[st].push_back(pair<string, int>(ed, tmp));
		mp[ed].push_back(pair<string, int>(st, tmp));
	}
	
	Dijkstra(mp, cost, vis, st);
	/*for (auto x : path["GDN"]) {
		cout << x << endl;
	}*/
	int numpath = 0;
	dfs(hp, numpath, st, "ROM", 0, vector<string>());
	sort(res.begin(), res.end(), cmp);
	cout << numpath << " " << cost["ROM"] << " " << res[0].first << " " << res[0].first / (res[0].second.size()-1) << endl;
	for (int i = res[0].second.size() - 1; i >= 0; i--) {
		if (i != 0)
			cout << res[0].second[i] << "->";
		else
			cout << res[0].second[i];
	}

}
