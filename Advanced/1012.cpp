//哈希加index排序

#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<unordered_map>
#include<vector>
using namespace std;

int num, mes;

struct grades {
	string Id;
	int c, m, e, a;
	grades(string id,int cc, int mm, int ee, int aa) :Id(id),c(cc), m(mm), e(ee), a(aa) {};
};
bool cmp1(grades &g1, grades &g2) {
	return g1.c > g2.c ? true : false;
}
bool cmp2(grades &g1, grades &g2) {
	return g1.m > g2.m ? true : false;
}
bool cmp3(grades &g1, grades &g2) {
	return g1.e > g2.e ? true : false;
}
bool cmp4(grades &g1, grades &g2) {
	return g1.a > g2.a ? true : false;
}

void Input(vector<grades> &g,vector<string> &m) {
	cin >> num >> mes;
	for (int i = 0; i < num; i++) {
		string sid;
		int cpl, math, eng,aver;
		double tmpaver;
		cin >> sid >> cpl >> math >> eng ;
		tmpaver = (cpl + math + eng) / 3.0;
		if ((tmpaver - (cpl + math + eng) / 3) >= 0.5)
			aver = (cpl + math + eng) / 3 + 1;
		else
			aver = (cpl + math + eng) / 3;
		grades tmp(sid, cpl, math, eng, aver);
		g.push_back(tmp);
	}
	for (int i = 0; i < mes; i++) {
		string sid;
		cin >> sid;
		m.push_back(sid);
	}
}

void theBestRank(vector<grades> &g, vector<string> &M) {
	sort(g.begin(), g.end(), cmp1);
	unordered_map<string, int> cpl;
	for (int i = 0; i < num; i++) {
		cpl[g[i].Id] = i + 1;
		int j = i+1;
		while (j < num) {
			if (g[j].c == g[i].c) {
				cpl[g[j].Id] = i + 1;
				j++;
			}
			else
				break;
		}
		i = j - 1;
	}
	sort(g.begin(), g.end(), cmp2);
	unordered_map<string, int> math;
	for (int i = 0; i < num; i++) {
		math[g[i].Id] = i + 1;
		int j = i + 1;
		while (j < num) {
			if (g[j].m == g[i].m) {
				math[g[j].Id] = i + 1;
				j++;
			}
			else
				break;
		}
		i = j - 1;
	}
	sort(g.begin(), g.end(), cmp3);
	unordered_map<string, int> eng;
	for (int i = 0; i < num; i++) {
		eng[g[i].Id] = i + 1;
		int j = i + 1;
		while (j < num) {
			if (g[j].e == g[i].e) {
				eng[g[j].Id] = i + 1;
				j++;
			}
			else
				break;
		}
		i = j - 1;
	}
	sort(g.begin(), g.end(), cmp4);
	unordered_map<string, int> aver;
	for (int i = 0; i < num; i++) {
		aver[g[i].Id] = i + 1;
		int j = i + 1;
		while (j < num) {
			if (g[j].a == g[i].a) {
				aver[g[j].Id] = i + 1;
				j++;
			}
			else
				break;
		}
		i = j - 1;
	}
	for (int i = 0; i < mes; i++) {
		if (cpl.find(M[i]) == cpl.end()) {
			cout << "N/A" << endl;
		}
		else {
			int c = cpl[M[i]], m = math[M[i]], e = eng[M[i]], a = aver[M[i]];
			if (a <= m && a <= e && a <= c) {
				cout << a << " " << "A" << endl;
			}
			else if (c < a&&c <= m && c <= e) {
				cout << c << " " << "C" << endl;
			}
			else if (m < a&&m < c&&m <= e) {
				cout << m << " " << "M" << endl;
			}
			else if (e < a&&e < c&&e < m) {
				cout << e << " " << "E" << endl;
			}
		}
	}
}

int main() {
	vector<grades> gra;
	vector<string> str;
	Input(gra, str);
	theBestRank(gra, str);

}
