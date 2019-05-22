//由于直接二维数组n^2暴力求解超时 所以利用动态规划的思路 在遍历每个点的时候我们保留它的一个求和然后再往后遍历的时候利用这个和做文章

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define IMAX 2147483647

int num, val;
vector<int> dim;

void Input() {
	cin >> num >> val;
	dim.push_back(0);
	for (int i = 1; i <= num; i++) {
		int tmp;
		scanf("%d",&tmp);
		dim.push_back(tmp);
	}
}

void ShoppinginMars() {
	int tmp = IMAX;
	vector<pair<int, int>> res;
	int sum = 0, sz = num,i=1;
	for (int l = 1; l <= num; l++) {
		while (i <= num) {
			sum += dim[i];
			if (sum >= val) {
				if (sum < tmp) {
					res.clear();
					res.push_back(pair<int, int>(l, i));
					tmp = sum;
				}
				else if (sum == tmp) {
					res.push_back(pair<int, int>(l, i));
				}
				if (i == l) {
					sum = 0;
					i++;
				}
				else{
					sum -= dim[l];
					sum -= dim[i];
				}
				break;
			}
			i++;
		}
		
	}
	sort(res.begin(), res.end());
	for (pair<int,int> x : res) {
		printf("%d-%d\n", x.first, x.second);
	}
}


int main() {
	Input();
	ShoppinginMars();
	//system("pause");
}
