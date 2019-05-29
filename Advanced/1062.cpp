//参数排序题 在输入的时候就把所有的成员按照规则分好类 最后再按照规则排序即可#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Man {
	int Id;
	int T, V;
	Man(int x,int y, int z) :Id(x),V(y), T(z) {};
};

vector<Man> Sage, Noble, Fool, Small;

void Input() {
	int num,low,high;
	scanf("%d %d %d", &num,&low,&high);
	//cout << num << " " << low<<" "<<high << endl;
	for (int i = 0; i < num; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (y >= high && z >= high) {
			
			Sage.push_back(Man(x,y, z));
		}
		else if (y >= high && z >= low) {
			Noble.push_back(Man(x,y, z));
		}
		else if (y >= low && z >= low && y >= z) {
			Fool.push_back(Man(x,y, z));
		}
		else if (y >= low && z >= low) {
			Small.push_back(Man(x,y, z));
		}
	}
}

bool cmp(Man &p1,Man &p2) {
	if (p1.T + p1.V > p2.T + p2.V)
		return true;
	else if (p1.T + p1.V == p2.T + p2.V) {
		if (p1.V > p2.V)
			return true;
		else if (p1.V == p2.V) {
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

void TalentandVirtue() {
	sort(Sage.begin(), Sage.end(), cmp);
	sort(Noble.begin(), Noble.end(), cmp);
	sort(Fool.begin(), Fool.end(), cmp);
	sort(Small.begin(), Small.end(), cmp);
	cout << Sage.size() + Noble.size() + Fool.size() + Small.size() << endl;
	for (Man x : Sage) {
		printf("%08d %d %d\n", x.Id, x.V, x.T);
	}
	for (Man x : Noble) {
		printf("%08d %d %d\n", x.Id, x.V, x.T);
	}
	for (Man x : Fool) {
		printf("%08d %d %d\n", x.Id, x.V, x.T);
	}
	for (Man x : Small) {
		printf("%08d %d %d\n", x.Id, x.V, x.T);
	}
}

int main() {
	Input();
	TalentandVirtue();


}

