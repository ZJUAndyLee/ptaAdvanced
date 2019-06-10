//注意要排除结尾有空格的情况

#include <vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

string same(string &s1,string &s2) {
	int i = 0, j = 0;
	for (; i < s1.size()&&s1[i] == ' '; i++);
	for (; j < s2.size()&&s2[j] == ' '; j++);
	int ii = i, jj = j;
	for (; ii < s1.size() && jj < s2.size() && s1[ii] == s2[jj]; ii++, jj++);
	string tmps = s1.substr(i, ii - i);
	return tmps;
}

int main() {
	int num;
	cin >> num;
	cin.ignore();
	vector<string> svec;
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	
	for (int i = 1; i < num; i++) {
		string tmps;
		getline(cin, tmps);
		reverse(tmps.begin(), tmps.end());
		
		str = same(str, tmps);
	}
	reverse(str.begin(), str.end());
	if (!str.empty())
		cout << str << endl;
	else
		cout << "nai" << endl;

}
