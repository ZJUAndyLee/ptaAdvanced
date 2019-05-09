#include<vector>
#include<iostream>
#include<iomanip>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
//这个题说实话有点傻X  当没有满足条件的通话记录的时候这个人信息不要被输出
string month;

struct cms {
	int ste;
	string t;
	int d, h, m;
	cms(int s, string time,int day, int hr, int min) : ste(s),t(time), d(day), h(hr), m(min) {};
};

struct per {
	string t1, t2;
	int min;
	double res;
	per(string t11, string t22, int m, double r) :t1(t11), t2(t22), min(m), res(r) {};
};

bool cmp(cms &c1, cms &c2) {
	if (c1.d > c2.d)
		return false;
	else if (c1.d == c2.d) {
		if (c1.h > c2.h)
			return false;
		else if (c1.h == c2.h) {
			if (c1.m > c2.m) {
				return false;
			}
			return true;
		}
		return true;
	}
	return true;
}
void Input(vector<int> &cost,map<string,vector<cms>> &g) {
	for (int i = 0; i < 24; i++) {
		int tmp;
		cin >> tmp;
		cost.push_back(tmp);
	}
	cost.push_back(cost[0]);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string name, time, state;
		cin >> name >> time >> state;
		int st=0,day, hr, min;
		if (state[1] == 'n') {
			st = 1;
		}
		else {
			st = 0;
		}
		for (int i = 0; i < time.length(); i+=3) {
			switch (i)
			{
			case 3:
				day = (time[i] - '0') * 10 + (time[i + 1] - '0');
				break;
			case 6:
				hr = (time[i] - '0') * 10 + (time[i + 1] - '0');
				break;
			default:
				min = (time[i] - '0') * 10 + (time[i + 1] - '0');
				break;
			}
		}
		month = time.substr(0, 2);
		time = time.substr(3, 8);
		g[name].push_back(cms(st, time, day, hr, min));
	}
}

void PhoneBills(vector<int> &cost, map<string, vector<cms>> &g){
	for (auto x : g) {
		sort(x.second.begin(), x.second.end(), cmp);
		int sz = x.second.size();
		double tres = 0.0;
		vector<per> vec;
		for (int i = 0; i < sz - 1;i++) {
			if (x.second[i].ste == 1) {
				if (x.second[i+1].ste == 0) {
					int res = 0, tmph = x.second[i].h, tmpmin = 0;
					while (1) {
						if (x.second[i].d < x.second[i + 1].d) {
							if (tmph < 24) {
								res +=  (60 - x.second[i].m) * cost[tmph] + x.second[i].m*cost[tmph + 1];
								tmpmin += 60;
								tmph++;
							}
							else {
								tmph = 0;
								x.second[i].d++;
							}
						}
						else {
							if (tmph < x.second[i + 1].h) {
								res += (60 - x.second[i].m) * cost[tmph] + x.second[i].m*cost[tmph + 1];
								tmpmin += 60;
								tmph++;
							}
							else {
								if (x.second[i].m > x.second[i + 1].m) {
									res -= (x.second[i].m - x.second[i + 1].m)*cost[tmph];
									tmpmin -= x.second[i].m - x.second[i + 1].m;
								}
								else {
									res += (x.second[i + 1].m - x.second[i].m)*cost[tmph];
									tmpmin += x.second[i + 1].m - x.second[i].m;
								}
								break;
							}
						}
					}
					tres += res / 100.0;
					vec.push_back(per(x.second[i].t, x.second[i + 1].t, tmpmin, res / 100.0));
				}
			}
		}
		if (!vec.empty()) {
			cout << x.first << " " << month << endl;
			for (auto iter : vec) {
				cout << iter.t1 << " " << iter.t2 << " " << iter.min << " $" << fixed << setprecision(2) << iter.res << endl;
			}
			cout << "Total amount: $" << fixed << setprecision(2) << tres << endl;
		}
	}
}

int main() {
	vector<int> vec;
	map<string, vector<cms>> gra;
	vector<pair<int, int>> v;
	Input(vec, gra);
	PhoneBills(vec, gra);

}
