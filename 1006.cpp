//git test
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

struct member {
	string ID, st, et;
};

void outp(member *p,int n) {
	vector<int> tmp1;
	vector<int> tmp2;
	int j = 0,t,tmp;
	for (int i = 0; i < n; i++) {
		if (!j) { 
			t = (p[i].st[0] - '0') * 10 + (p[i].st[1] - '0'); 
			tmp1.push_back(i);
		}
		else {
			tmp= (p[i].st[0] - '0') * 10 + (p[i].st[1] - '0');
			if(tmp==t) tmp1.push_back(i);
			else if (tmp < t) {
				t = tmp;
				tmp1.clear();
				tmp1.push_back(i);
			}
		}
		j++;
	}
	j = 0;
	for (int i = 0; i < tmp1.size(); i++) {
		if (!j) {
			t = (p[tmp1[i]].st[3] - '0') * 10 + (p[tmp1[i]].st[4] - '0');
			tmp2.push_back(tmp1[i]);
		}
		else {
			tmp = (p[tmp1[i]].st[3] - '0') * 10 + (p[tmp1[i]].st[4] - '0');
			if (tmp == t) tmp2.push_back(tmp1[i]);
			else if (tmp < t) {
				t = tmp;
				tmp2.clear();
				tmp2.push_back(tmp1[i]);
			}
		}
		j++;
	}
	j = 0;
	int x;
	for (int i = 0; i < tmp2.size(); i++) {
		if (!j) {
			t = (p[tmp2[i]].st[6] - '0') * 10 + (p[tmp2[i]].st[7] - '0');
			x = tmp2[i];
		}
		else {
			tmp = (p[tmp2[i]].st[6] - '0') * 10 + (p[tmp2[i]].st[7] - '0');
			if (tmp < t) {
				t = tmp;
				x = tmp2[i];
			}
		}
		j++;
	}
	cout << p[x].ID << " ";
	j = 0;
	tmp1.clear();
	tmp2.clear();
	for (int i = 0; i < n; i++) {
		if (!j) {
			t = (p[i].et[0] - '0') * 10 + (p[i].et[1] - '0');
			tmp1.push_back(i);
		}
		else {
			tmp = (p[i].et[0] - '0') * 10 + (p[i].et[1] - '0');
			if (tmp == t) tmp1.push_back(i);
			else if (tmp > t) {
				t = tmp;
				tmp1.clear();
				tmp1.push_back(i);
			}
		}
		j++;
	}
	j = 0;
	for (int i = 0; i < tmp1.size(); i++) {
		if (!j) {
			t = (p[tmp1[i]].et[3] - '0') * 10 + (p[tmp1[i]].et[4] - '0');
			tmp2.push_back(tmp1[i]);
		}
		else {
			tmp = (p[tmp1[i]].et[3] - '0') * 10 + (p[tmp1[i]].et[4] - '0');
			if (tmp == t) tmp2.push_back(tmp1[i]);
			else if (tmp > t) {
				t = tmp;
				tmp2.clear();
				tmp2.push_back(tmp1[i]);
			}
		}
		j++;
	}
	j = 0;
	for (int i = 0; i < tmp2.size(); i++) {
		
		if (!j) {
			t = (p[tmp2[i]].et[6] - '0') * 10 + (p[tmp2[i]].et[7] - '0');
			x = tmp2[i];
		}
		else {
			tmp = (p[tmp2[i]].et[6] - '0') * 10 + (p[tmp2[i]].et[7] - '0');
			if (tmp > t) {
				t = tmp;
				x = tmp2[i];
			}
		}
		j++;
	}
	cout << p[x].ID;
}

int main() {
	int n;
	cin >> n;
	member *p = new member[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].ID >> p[i].st >> p[i].et;
	}
	outp(p, n);
}
