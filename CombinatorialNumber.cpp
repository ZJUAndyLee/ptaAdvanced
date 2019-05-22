#include<iostream>
#include<vector>
using namespace std;
//如何构建组合数！
const int N = 5;
const int M = 3;

using namespace std;
int vis[N + 1];    //标志，
int ans = 0;    //含有的组合数 的数量
int num[M + 1];    //选出来的数放在num数组里面

void solve() {        //在solve函数里面处理
	for (int i = 1; i < M + 1; i++)
		cout << num[i] << " ";
	cout << endl;
}

void dfs(int index) {    //挑选的第index+1个数
	if (index == M) {
		solve();
		ans++;
		return;
	}
	for (int i = num[index] + 1; i < N + 1; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			num[index + 1] = i;
			dfs(index + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	dfs(0);    //回溯开始
	cout << endl << ans;
}
