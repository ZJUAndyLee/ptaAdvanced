//模拟数进入堆中的模式

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int N, M, num;

bool judge(queue<int> &q) {
	int last = 0;
	stack<int> stk;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp < last) {//当出现的数小于前面出现过的最大的数 那么该数必定为堆顶的数
			if (!stk.empty()) {
				if (stk.top() == tmp) 
					stk.pop();
				else
					return false;
			}
			else
				return false;
		}
		else {//当出现的数大于前面出现过的最大的数 那么就把他们俩的差全部push进堆中
			for (int i = last + 1; i < tmp; i++) {
				stk.push(i);
			}
		}
		if (stk.size() >= N) {//由于前面push进了堆中所以这里要判断堆的大小 注意这里是大于等于而不是大于
			return false;
		}
		last = max(tmp,last);
	}
    return true;
}

int main()
{
	cin >> N >> M >> num;
	for (int i = 0; i < num; i++) {
		queue<int> qe;
		for (int i = 0; i < M; i++) {
			int tmp;
			cin >> tmp;
			qe.push(tmp);

		}
		if (judge(qe))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}
