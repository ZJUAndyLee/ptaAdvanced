#include<iostream>
#include<string>
#include<string.h>
#include<stack>
using namespace std;

int tosum() {
	string num;
	int sum = 0;
	cin >> num;
	for (int i = 0; i < num.length(); i++) {
		sum += num[i] - '0';
	}
	return sum;

}

string exchange(int n) {
	switch (n)  {
	case 0: return "zero";
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "eight";
	default: return "nine";
	}
}

void outp(int n) {
	stack<int> sk;
	int tmp;
	while (1) {
		tmp = n % 10;
		sk.push(tmp);
		n = n / 10;
		if (!n) break;
	}
	int i = 0;
	while (!sk.empty()) {
		tmp = sk.top();
		sk.pop();
		if(i==0) cout << exchange(tmp);
		else cout << " " << exchange(tmp);
		i++;
	}
}

int main() {
	int sum;
	sum = tosum();
	outp(sum);
}
