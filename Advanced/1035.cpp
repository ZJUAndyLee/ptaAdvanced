//考的是is are的用法。。。
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;
int N;

struct cons {
	string name;
	string pwd;
	cons(string s1, string s2) :name(s1), pwd(s2) {};
};
vector<cons> vec;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		vec.push_back(cons(s1, s2));
	}
}



void Password() {
	vector<cons> res;
	for (auto &x : vec) {
		int idx = 0;
		for (int i = 0; i < x.pwd.size(); i++) {
			switch (x.pwd[i]){
			case '1':
				idx = 1;
				x.pwd[i] = '@';
				break;
			case '0':
				idx = 1;
				x.pwd[i] = '%';
				break;
			case'l':
				idx = 1;
				x.pwd[i] = 'L';
				break;
			case'O':
				idx = 1;
				x.pwd[i] = 'o';
				break;
			}
		}
		if (idx == 1) {
			res.push_back(x);
		}
	}
	if (res.empty()) {
        if(N==1)
		    cout << "There is " << N << " account and no account is modified\n";
        else
            cout << "There are " << N << " accounts and no account is modified\n";
		return;
	}
	cout << res.size() << endl;
	for (auto x : res) {
		cout << x.name << " " << x.pwd << endl;
	}
}

int main() {
	Input();
	Password();
	

}
