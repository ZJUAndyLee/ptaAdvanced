//通过一个是否为素数的函数判断 以及一个连续的相除得到多项式

#include<iostream>
#include<map>
using namespace std;

int isPrime(int num) {
	if (num % 2 == 0) {
		return 2;
	}
	if (num % 3 == 0) {
		return 3;
	}
	if (num % 5 == 0) {
		return 5;
	}
	if (num % 7 == 0){
		return 7;
	}
	int ct = 11;
	while (ct < num / 7) {
		if (num%ct == 0)
			return ct;
		ct += 2;
	}
	return 0;
}

int main() {
	int x;
	scanf("%d", &x);
	int tmp = x;
	map<int, int> res;
	while (x>1) {
		int fac = isPrime(x);
		//cout << fac << endl;
		if (fac > 0) {
			res[fac]++;
		}
		else {
			res[x]++;
			break;
		}
		x = x / fac;
	}
	if (tmp > 1) {
		printf("%d=", tmp);
		int  ct = 0;
		for (pair<int, int> x : res) {
			if (ct == 0) {
				if (x.second > 1) {
					printf("%d^%d", x.first, x.second);
				}
				else if (x.second == 1) {
					printf("%d", x.first);
				}
			}
			else {
				if (x.second > 1) {
					printf("*%d^%d", x.first, x.second);
				}
				else if (x.second == 1) {
					printf("*%d", x.first);
				}
			}
			ct++;
		}
	}
	else {
		printf("%d=%d", tmp, tmp);
	}

}
