//hash 但是由于map会超时 所以只能自己写cmp函数调用标准库的sort函数

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int num, val;
vector<int> M;
vector<vector<string>> g;
void Input() {
	scanf("%d %d", &num, &val);
	g.assign(val + 1, vector<string>());
	for (int i = 0; i < num; i++) {
		char c[4];
		int tmpi;
		scanf("%s %d", &c, &tmpi);
		for (int j = 0; j < tmpi; j++) {
			int x;
			scanf("%d", &x);
			g[x].push_back(c);
		}
	}
}
bool cmp(string &s1,string &s2){
    return s1>s2?false:true;
}
void StudentListforCourse() {
	for (int i = 1; i <= val; i++) {
		int sz = g[i].size();
        printf("%d %d\n", i, sz);
        sort(g[i].begin(),g[i].end(),cmp);
		for (string x : g[i]) {
			printf("%s\n", x.c_str());
		}
	}
}




int main() {
	Input();
	StudentListforCourse();
	//system("pause");
}
