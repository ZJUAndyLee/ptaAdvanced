//数字黑洞 注意是当输入为6174时也要输出 "7641 - 1467 = 6174" 
 
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
	int num;
	cin >> num;
    if (num == 6174) {
		cout << "7641 - 1467 = 6174" << endl;
	}
	vector<pair<int, int>> res;
	while (num!=6174) {
		vector<int> v;
		int tmp = num;
		int ct = 0;
		while (ct < 4) {
			v.push_back(tmp % 10);
			tmp = tmp / 10;
			ct++;
		}
		sort(v.begin(), v.end());
		
		int bg = 0, sm = 0, i = 0;
		for (; i < v.size(); i++) {
			bg += v[i] * pow(10, i);
		}
		for (i = i - 1; i >= 0; i--) {
			sm += v[i] * pow(10, 3 - i);
		}
		res.push_back(pair<int, int>(bg, sm));
		if (sm == bg)
			break;
		num = bg - sm;
	}
	
	for (pair<int, int> x : res) {
		if (x.first == x.second) {
			printf("%04d - %04d = %04d\n", x.first, x.second, 0);
			break;
		}
		int tmp = x.first - x.second;
		printf("%04d - %04d = %04d\n", x.first, x.second, tmp);
	}

}

