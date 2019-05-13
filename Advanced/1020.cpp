#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

// 中序遍历加后序遍历确定二叉树，注意是二叉树而不是二叉搜索树

int Num;
vector<vector<int>> g;
void Input(vector<int> &pod, vector<int> &iod) {
	cin >> Num;
	for (int i = 0; i < Num; i++) {
		int tmp;
		cin >> tmp;
		pod.push_back(tmp);
	}
	for (int i = 0; i < Num; i++) {
		int tmp;
		cin >> tmp;
		iod.push_back(tmp);
	}
}

void TreeTraversals(vector<int> &pod, vector<int> &iod,int root) {
	if (pod.empty())
		return;
	int tmp = pod.back();
	g[root].push_back(tmp);
	vector<int> tmppl, tmpil, tmppr, tmpir;
	int j = 0;
	while (j<iod.size()) {
		if (iod[j] == tmp) {
			tmppl.insert(tmppl.end(), pod.begin(), pod.begin() + j);
			tmpil.insert(tmpil.end(), iod.begin(), iod.begin() + j);
			break;
		}
		j++;
	}
	int i = pod.size() - j - 1;
	if (i > 0) {
		tmppr.insert(tmppr.end(), pod.begin() + j, pod.end() - 1);
		tmpir.insert(tmpir.end(), iod.begin() + j + 1, iod.end());
	}
	TreeTraversals(tmppl, tmpil, tmp);
	TreeTraversals(tmppr, tmpir, tmp);
}


int main() {
	g.assign(31, vector<int>());
	vector<int> p, i;
	Input(p, i);
	int root = p.back();
	TreeTraversals(p, i,0);
	int iter = 0;
	queue<int> qe;
	qe.push(root);
	while (!qe.empty()) {
		int tmp = qe.front();
		qe.pop();
		if (!g[tmp].empty()) {
			for (auto x : g[tmp]) {
				qe.push(x);
			}
		}
		if (iter == 0)
			cout << tmp;
		else
			cout << " " << tmp;
		iter++;
	}
 
                                        }
