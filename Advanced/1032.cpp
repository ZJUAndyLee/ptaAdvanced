//先由一个字符串建立一个字符链表 链表由一个哈希map构成 之后再对第二个字符串进行检查当第一个出现重复的字符的时候可以说明后面重复的字符串了


#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
unordered_map<int, int> mp;

int ad1, ad2, num;

void Input() {
	cin >> ad1 >> ad2 >> num;
	for (int i = 0; i < num; i++) {
		int x, y;
		char c;
		scanf("%d %c %d",&x,&c,&y);
		mp.insert(pair<int, int>(x, y));
	}
}

void Sharing() {
	if (ad1 == ad2) {
		printf("%05d", ad1);
		return;
	}
	unordered_map<int, int> lt1;
	int tmp = ad1;
	while (tmp != -1) {
		lt1[tmp] = mp[tmp];
		tmp = mp[tmp];
	}
	tmp = ad2;
	while (tmp != -1) {
		if (lt1.find(mp[tmp]) == lt1.end()) {
			tmp = mp[tmp];
		}
		else {
			tmp = mp[tmp];
			break;
		}
	}
	if (tmp == -1)
		cout << -1;
	else
		printf("%05d", tmp);
}

int main() {
	Input();
	Sharing();

}
