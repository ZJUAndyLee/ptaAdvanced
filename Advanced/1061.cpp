//看清题目 题目说的的是 前两个数组中第一个相同的大写字母 以及第二个相同的大写或者整数 最后是后两个字符串中第一个相等的英文字母的位置

#include <string>
#include <iostream>
using namespace std;

int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int sz1 = int(s1.size()) < int(s2.size()) ? int(s1.size()) : int(s2.size());
	char day, hour;
	int ct = 0;
	for (int i = 0; i < sz1; i++) {
		
		if (s1[i] == s2[i]&&(s1[i]>='A'&&s1[i]<='G')&&ct==0) {//(s1[i]>='0'&&s1[i]<='9')
			day = s1[i];
			ct++;
		}
		else if (s1[i] == s2[i] && ((s1[i] >= 'A'&&s1[i] <= 'N') || (s1[i] >= '0'&&s1[i] <= '9')) && ct == 1) {
			hour = s1[i];
			break;
		}
	}
	string week[7];
	week[0] = "MON", week[1] = "TUE", week[2] = "WED", week[3] = "THU", week[4] = "FRI", week[5] = "SAT", week[6] = "SUN";
	int h = 0;
	if (hour >= '0'&&hour <= '9') {
		h = hour - '0';
	}
	else {
		h = hour - 'A' + 10;
	}
	int min;
	int sz2 = int(s3.size()) < int(s4.size()) ? int(s3.size()) : int(s4.size());
	for (int i = 0; i < sz2; i++) {
		if (s3[i] == s4[i] && ((s3[i] >= 'a'&&s3[i] <= 'z') || (s3[i] >= 'A'&&s3[i] <= 'Z'))) {
			min = i;
			break;
		}
	}
	int d = day - 'A';
	//cout << d << endl;
	cout << week[d];
	printf(" %02d:%02d", h, min);
	//system("pause");

}
