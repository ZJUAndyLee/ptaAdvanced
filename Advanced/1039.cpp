哈希表的运用

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
int numq, numc;
unordered_map<string, set<int>> List;
vector<string> query;

void Input() {
	cin >> numq >> numc;
	for (int i = 0; i < numc; i++) {
		int course, stu;
		cin >> course >> stu;
		for (int i = 0; i < stu; i++) {
			char tmpc[4];
			scanf("%s",&tmpc);
			string tmps = tmpc;
			List[tmps].insert(course);
		}
	}
	for (int i = 0; i < numq; i++) {
		char tmpc[4];
		scanf("%s", &tmpc);
		string tmps = tmpc;
		query.push_back(tmps);
	}
}

void CourseListforStudent() {
	for (auto x : query) {
		cout << x;
		cout << " " << List[x].size();
		for (auto y : List[x]) {
			cout << " " << y;
		}
		cout << endl;
	}
}

int main() {
	Input();
	CourseListforStudent();
}
