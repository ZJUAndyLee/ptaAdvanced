#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int N;

struct stu {
	string name;
	string id;
	int grade;
	stu(string s1, string s2, int n) :name(s1), id(s2), grade(n) {};
};
vector<stu> Male;
vector<stu> feMale;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		string c;
		int num;
		cin >> s1 >> c >> s2 >> num;
		if (c == "M") {
			Male.push_back(stu(s1, s2, num));
		}
		else {
			feMale.push_back(stu(s1, s2, num));
		}
	}
}

bool cmp1(stu &p1,stu &p2) {
	return p1.grade > p2.grade ? false: true;
}
bool cmp2(stu &p1, stu &p2) {
	return p1.grade > p2.grade ? true : false;
}

void BoysvsGirls() {
	sort(Male.begin(), Male.end(), cmp1);
	sort(feMale.begin(), feMale.end(), cmp2);
	if (Male.empty() || feMale.empty()) {
		if (feMale.empty())
			cout << "Absent" << endl;
		else
			cout << feMale[0].name << " " << feMale[0].id << endl;
		if (Male.empty())
			cout << "Absent" << endl;
		else
			cout << Male[0].name << " " << Male[0].id << endl;
		
		cout << "NA\n";
	}
	else {
		cout << feMale[0].name << " " << feMale[0].id << endl;
		cout << Male[0].name << " " << Male[0].id << endl;
		cout << feMale[0].grade - Male[0].grade << endl;
	}
}

int main() {
	Input();
	BoysvsGirls();
	

}
