//sort函数注意要按照规则进行否则会出现段错误 cmp函数不能用>=或<= 只能用>或<
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N, M, K;
struct person {
	int Ge, Gi;
	int ch[5];
	int rank;
	int num;
	person() { rank = 0; };
};

vector<int> sch(100, 0);

bool cmp(person &p1, person &p2) {
	if (p1.Ge + p1.Gi > p2.Ge + p2.Gi)
		return true;
	else if (p1.Ge + p1.Gi == p2.Ge + p2.Gi) {
		if (p1.Ge > p2.Ge)
			return true;
		return false;
	}
	else
		return false;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	vector<person> List(N, person());
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		sch[i] = tmp;
	}
	for (int i = 0; i < N; i++) {
		int g1, g2;
		scanf("%d %d", &g1, &g2);
		List[i].Ge = g1;
		List[i].Gi = g2;
		List[i].num = i;
		for (int j = 0; j < K; j++) {
			int tmp;
			scanf("%d", &tmp);
			List[i].ch[j] = tmp;
		}
	}
	sort(List.begin(), List.end(), cmp);

	int idx = 1, total = List[0].Ge + List[0].Gi, ge = List[0].Ge;
	for (int i = 0; i < N; i++) {
		if (List[i].Ge + List[i].Gi == total) {
			if (List[i].Ge == ge)
				List[i].rank = idx;
			else {
				List[i].rank = i + 1;
				idx = i + 1;
				ge = List[i].Ge;
			}
		}
		else {
			List[i].rank = i + 1;
			idx = i + 1;
			total = List[i].Ge + List[i].Gi;
			ge = List[i].Ge;
		}
	}
	vector<int> Rank(100, 0);
	vector<vector<int>> res(100, vector<int>());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (sch[List[i].ch[j]] > 0) {
				res[List[i].ch[j]].push_back(List[i].num);
				sch[List[i].ch[j]]--;
				if (sch[List[i].ch[j]] == 0) {
					Rank[List[i].ch[j]] = List[i].rank;
				}
				break;
			}
			else if (Rank[List[i].ch[j]] == List[i].rank) {
				res[List[i].ch[j]].push_back(List[i].num);
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		sort(res[i].begin(), res[i].end());
		for (int j = 0; j < res[i].size(); j++) {
			if (j != 0) printf(" ");
			printf("%d", res[i][j]);
		}
		printf("\n");
	}
}

