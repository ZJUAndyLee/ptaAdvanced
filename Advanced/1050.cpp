//建立一个排除字典 然后遍历字符串 如果不在字典中直接加到结果数组中去

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


int main()
{
	string str;
	string idx;
	getline(cin, str, '\n');
	getline(cin, idx, '\n');
	unordered_set<char> hs;
	for (char c : idx) {
		hs.insert(c);
	}
	vector<char> res;
	for (char c : str) {
		if (hs.find(c) == hs.end())
			res.push_back(c);
	}
	for (char c : res) {
		printf("%c",c);
	}

}
