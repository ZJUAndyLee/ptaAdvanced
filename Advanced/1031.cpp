/*
*注意如何得到左中右三条边的字符个数的关系即可
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int sz = str.size();
	int n = (sz + 2) / 3;
	int i = 0;
	for (; i < n-1; i++) {
		cout << str[i];
		for (int j = 0; j < sz - 2 * n; j++) {
			cout << " ";
		}
		cout << str[sz - 1 - i] << endl;
	}
	for (; i < sz - n + 1; i++) {
		cout << str[i];
	}
}
