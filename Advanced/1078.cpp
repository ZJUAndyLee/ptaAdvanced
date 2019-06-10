//二次探测 注意只有+ptr^2没有- 素数的判断也要注意

#include <iostream>
#include<vector>
using namespace std;

int num, sz;

bool isprime(int a) {
	if (a == 1) return false;
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return false;
	return true;
}

int ExChange(int n) {
	while (!isprime(n))
		n++;
	return n;
}

int main() {
	int tmpsz;
	scanf("%d %d", &tmpsz, &num);
	sz = ExChange(tmpsz);
	vector<bool> hs(sz, false);
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		bool flag = true;
		for (int step = 0; step < sz; step++) {
			int pos = (tmp + step * step) % sz;
			if (!hs[pos]) {
				if (i != 0)printf(" ");
				printf("%d", pos);
				hs[pos] = true;
				flag = false;
				break;
			}
		}
		if (flag) {
			if (i != 0)printf(" ");
			printf("-");
		}
	}
}
