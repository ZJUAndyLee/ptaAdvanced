#include<vector>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int tag, rdx;

void Input(string &A,string &B) {
	cin >> A >> B >> tag >> rdx;
}

long long exchange(string &s,int r) {
	long long res = 0;
	int sz = s.size();
	for (int i = sz-1; i >=0;i--) {
		if (s[i] - '0' > 9) {
			int tmp = s[i] - 'a' + 10;
			res += tmp * pow(r, sz-1-i);
		}
		else {
			int tmp = s[i] - '0';
			res += tmp * pow(r, sz - 1 - i);
		}
	}
	return res;
}
void Radix(string &str1, string &str2) {
	long long tmp;
	tmp = exchange(str1, rdx);
	char max = 0;
	for (auto x : str2) {
		max = x > max ? x : max;
	}
	int tmpr = max > '9' ? max - 'a' + 11 : max - '0' + 1;
	
	while (1) {
		long long tmps2 = exchange(str2, tmpr);
		if (tmps2 == tmp) {
			cout << tmpr;
			break;
		}
		else if (tmps2 > tmp) {
			cout << "Impossible";
			break;
		}
		tmpr++;
	}
}

int main() {
	string N1, N2;
	Input(N1, N2);
	if (tag == 1)
		Radix(N1, N2);
	else
		Radix(N2, N1);
}

//一个点超时
