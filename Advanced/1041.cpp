//hash策略常用思路

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
int num;
vector<int> vec;
void Input() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d",&tmp);
		vec.push_back(tmp);
	}
}

void BeUnique() {
	unordered_map<int, int> hash;
	for (auto x : vec) 
		hash[x]++;
	int res = 0;
	for (auto x : vec) {
		if (hash[x] == 1) {
			res = x;
			break;
		}
	}
	if (res > 0) {
		cout << res;
	}
	else {
		cout << "None";
	}
}

int main() {
	Input();
	BeUnique();

}
