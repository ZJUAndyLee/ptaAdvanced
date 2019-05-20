//大小堆的应用 正数大堆负数小堆
#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
int Nc,Np;
priority_queue<int> Maxhc,Maxhs;
priority_queue<int, vector<int>, greater<int>> Minhc, Minhs;

void Input() {
	cin >> Nc;
	for (int i = 0; i < Nc; i++) {
		int tmp;
		scanf("%d",&tmp);
		if (tmp > 0)
			Maxhc.push(tmp);
		else
			Minhc.push(tmp);
	}
	cin >> Np;
	for (int i = 0; i < Np; i++) {
		int tmp;
		scanf("%d",&tmp);
		if (tmp > 0)
			Maxhs.push(tmp);
		else
			Minhs.push(tmp);
	}
}

void MagicCoupon() {
	int res = 0;
	while (!Maxhc.empty() && !Maxhs.empty()) {
		res += Maxhc.top()*Maxhs.top();
		//cout << Maxhc.top() << " " << Maxhs.top() << endl;
		Maxhc.pop(), Maxhs.pop();
	}
	while (!Minhc.empty() && !Minhs.empty()) {
		res += Minhc.top()*Minhs.top();
		//cout << Minhc.top() << " " << Minhs.top() << endl;
		Minhc.pop(), Minhs.pop();
	}
	cout << res;
}

int main() {
	Input();
	MagicCoupon();
	

}
