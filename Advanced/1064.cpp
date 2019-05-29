//通过完美二叉搜索树的性质 得到每棵树左子树的大小以及右子树的大小然后将树根填入完美二叉搜索树的对应的位置 然后递归调用 即可得到完美二叉搜索树的数组表示形式
//从而直接按顺序输出数组的每个元素就是完美二叉搜索树的的层序遍历

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;



vector<int> vec;
vector<int> res;

void CBT(vector<int> v,int pos) {
	int sz = v.size();
	if (sz == 0) {
		return;
	}
	if (sz == 1) {
		res[pos] = v[0];
		return;
	}
	int n = log(sz) / log(2);
	int last = sz - pow(2, n) + 1;
	int lt = 0, rt = 0;
	if (last >= pow(2, n - 1)) {
		lt = pow(2, n) - 1;
		rt = last;
	}
	else {
		lt = pow(2, n - 1)-1 + last;
		rt = pow(2, n - 1)-1;
	}
	
	res[pos] = v[lt];
	vector<int> lv(v.begin(), v.begin() + lt);
	vector<int> rv(v.begin() + lt + 1, v.end());
	if (lt > 0)
		CBT(lv, 2 * pos + 1);
	if (rt > 0) {
		CBT(rv, 2 * pos + 2);
	}
}

int main() {
	
	int num;
	cin>>num;
	res.assign(num, 0);
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	CBT(vec, 0);
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			cout << res[i];
		}
		else {
			cout << " " << res[i];
		}
	}


}

