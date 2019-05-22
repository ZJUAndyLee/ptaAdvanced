//直接新建一个中间数组然后赋值了

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
int num;
vector<int> shuff;
void Input() {
	cin >> num;
	shuff.push_back(0);
	for (int i = 1; i <= 54; i++) {
		int tmp;
		cin >> tmp;
		shuff.push_back(tmp);
	}
}

void exchang(int n) {
	int tmp = (n - 1) / 13;
	switch (tmp) {
	case 0:
		cout << "S" << (n - 1) % 13 + 1;
		break;
	case 1:
		cout << "H" << (n - 1) % 13 + 1;
		break;
	case 2:
		cout << "C" << (n - 1) % 13 + 1;
		break;
	case 3:
		cout << "D" << (n - 1) % 13 + 1;
		break;
	default:
		cout << "J" << (n - 1) % 13 + 1;
		break;
	}
}

void ShufflingMachine() {
	vector<int> card(55, 0);
	for (int i = 1; i <= 54; i++) {
		card[i] = i ;
	}
	for (int j = 0; j < num; j++) {
		vector<int> tmp(55, 0);
		
		for (int i = 1; i <= 54; i++) {
			tmp[shuff[i]] = card[i];
		}
		card = tmp;
	}
	for (int i = 1; i <= 54; i++) {
		if (i == 1) {
			exchang(card[i]);
		}
		else {
			cout << " ";
			exchang(card[i]);
		}
		
	}
}

int main() {
	Input();
	ShufflingMachine();
	//system("pause");
}
