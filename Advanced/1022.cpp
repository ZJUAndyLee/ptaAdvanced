#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<set>
#include<stdio.h>
using namespace std;

int Num, M;

//一个查找的问题 最最关键的是格式化输出 number作为一个7位数当他的输入不是一个七位数时前面需要用零补充 这个是最值得注意的地方

struct book {
	int num;
	string Aname, Pname, Tname, year;
	vector<string> kw;
	book(int n1, string str, string str1, string str2, vector<string> svec, string str3) :num(n1), Tname(str), Aname(str1), Pname(str2), kw(svec), year(str3) {};
};

void Input(vector<book>& liby, vector<string>& svec) {
	cin >> Num;
	for (int i = 0; i < Num; i++) {
		int n;
		cin >> n;
		cin.ignore();
		string aname, pname, tname;
		getline(cin, tname);
		getline(cin, aname);
		vector<string> tmps;
		string keyw;
		getline(cin, keyw);
		int lasti = 0;
		for (int i = 0; i < keyw.size(); i++) {
			if (keyw[i] == ' ') {
				string s = keyw.substr(lasti, i - lasti);
				lasti = i + 1;
				tmps.push_back(s);
			}
		}
		tmps.push_back(keyw.substr(lasti, keyw.size() - lasti));
		getline(cin, pname);
		string year;
		getline(cin, year);
		liby.push_back(book(n, tname, aname, pname, tmps, year));
	}
	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++) {
		string str;
		getline(cin, str);
		svec.push_back(str);
	}

}

void finds(string str, unordered_map<string, set<int>>& g) {
	if (g.find(str) != g.end()) {
		for (auto it = g[str].begin(); it != g[str].end(); it++) {

			printf("%07d\n", *it);
		}
	}
	else {
		cout << "Not Found" << endl;
	}
}

void DigitalLibrary(vector<book>& liby, vector<string>& svec) {
	unordered_map<string, set<int>> tit;
	unordered_map<string, set<int>> aut;
	unordered_map<string, set<int>> pub;
	unordered_map<string, set<int>> key;
	unordered_map<string, set<int>> year;
	for (auto x : liby) {
		tit[x.Tname].insert(x.num);
		aut[x.Aname].insert(x.num);
		pub[x.Pname].insert(x.num);
		for (auto y : x.kw) {
			key[y].insert(x.num);
		}
		year[x.year].insert(x.num);
	}
	for (auto x : svec) {
		cout << x << endl;
		int tmpi = x[0] - '0';
		string idx = x.substr(3, 80);
		switch (tmpi)
		{
		case 1:
			finds(idx, tit);
			break;
		case 2:
			finds(idx, aut);
			break;
		case 3:
			finds(idx, key);
			break;
		case 4:
			finds(idx, pub);
			break;
		case 5:
			finds(idx, year);
			break;
		}
	}

}

int main() {
	vector<book> lb;
	vector<string> s;
	Input(lb, s);
	DigitalLibrary(lb, s);



}
