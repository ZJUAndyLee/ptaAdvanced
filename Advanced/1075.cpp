/**关键字排序**/

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
int head, num1, num2;

struct PAT {
	int Id;
	int sum,perf;
	int g[6];
	PAT() {
		Id = 0;
		sum = 0;
		perf = 0;
		for (int i = 0; i <= 5; i++) {
			g[i] = -2;
		}
	};
};
vector<PAT> v(10001, PAT());
unordered_map<int, PAT> List;
int grade[5] = { 0 };

void Input() {
	scanf("%d %d %d", &head, &num1, &num2);
	int flag = 1;
	for (int i = 1; i <= num1; i++) {
		int tmpi;
		scanf("%d", &tmpi);
		grade[i] = tmpi;
	}
	for (int i = 0; i < num2; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (List[x].g[y] < z) {
			List[x].g[y] = z;
		}
	}
}

bool cmp(PAT &p1,PAT &p2) {
	if (p1.sum > p2.sum)
		return true;
	else if (p1.sum == p2.sum) {
		if (p1.perf > p2.perf)
			return true;
		else if (p1.perf == p2.perf) {
			if (p1.Id > p2.Id)
				return false;
			else
				return true;
		}
		else
			return false;
	}
	else
		return false;
}

void PATJudge() {
	vector<PAT> vec;
	for (auto x : List) {
		for (int i = 1; i <= num1; i++) {
			if (x.second.g[i] >= 0) {
				x.second.Id = x.first;
				x.second.sum += x.second.g[i];
			}
			if (x.second.g[i] == grade[i])
				x.second.perf++;
		}
		if (x.second.Id > 0)
			vec.push_back(x.second);
	}
	sort(vec.begin(), vec.end(), cmp);
	
	int idx = vec[0].sum, rank = 1;
	for (int i = 0; i < vec.size();i++) {
		if (vec[i].sum == idx) {
			printf("%d ", rank);
		}
		else {
			idx = vec[i].sum;
			rank = i + 1;
			printf("%d ", rank);
		}
		printf("%05d %d", vec[i].Id, vec[i].sum);
		for (int j = 1; j <= num1; j++) {
			if (vec[i].g[j] >= 0)
				printf(" %d", vec[i].g[j]);
			else if(vec[i].g[j]==-1)
				printf(" 0");
			else 
				printf(" -");
		}
		printf("\n");
	}
}

int main() {
	Input();
	PATJudge();
	//system("pause");

}

