/**这个题两种思路 首先利用最长递增子序算法来解决该问题 注意的是 大小顺序是自定义的需要重新操作
*最长递增子序：
*对于序列<a1,a2,a3,...,ak>我们求出以ai结尾的每个递增子序的长度 然后最大的值就是我们的结果
*对于每个ai我们可以对于已经得到的a1...ai-1的值遍历前面的每个点 对于任何 aj<=ai 我们只需要求 max(aj)+1 也就是ai的最长序列的值 当然对于任何递减序列 ai的值也就为 1
*但是该算法还是需要两个for循环 N^2的时间复杂度**/

/**我们还可以运用LIS(最长递增子序)的思路 利用二分查找优化我们的算法
*对于序列<a1,a2,a3,...,ak>我们可以维护一个递增数组对于每个点 首先判断是否大于等于该数组的最后的值 大于的话直接push_back()这时以该点结尾的最大递增子序的长度为数组的size
*若小于最后的值 我们利用二分查找找到第一个大于当前点的数 并且替换该数 返回该数的数组下标 以该点结尾的最大递增子序的长度为数组下标+1**/

/**二分查找：st(start)=0(数组起点) ed(end) = size()-1(数组终点) mid=(st+ed)/2
*while(st<ed) {
*  if(arr[mid]<=key)
*      st=mid+1 这里必须加1否无法到达数组的终点
*    else
*      ed=mid
*    mid = (st+ed)/2}
* return mid
**/


#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int num, val;
vector<int> M;
vector<int> List;
void Input() {
	cin >> num;
	M.assign(num + 1, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		M[tmp] = i;
	}
	cin >> val;
	for (int i = 0; i < val; i++) {
		int tmp;
		cin >> tmp;
		if (M[tmp] > 0)
			List.push_back(tmp);
	}
}

bool cmp(int x,int y) {
	return M[x] > M[y] ? false : true;
}

void FavoriteColorStripe() {
	int sz = List.size();
	if (sz == 1) {
		cout << 1;
		return;
	}
	vector<int> dp(sz+1,1);
	int res = 0;
	for (int i = 2; i < sz+1; i++) {
		for (int j = 1; j < i; j++) {
			if (M[List[j-1]] <= M[List[i-1]]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(dp[i], res);
	}

	cout << res;
}


int main() {
	Input();
	FavoriteColorStripe();
	//system("pause");
}


//二分查找
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int num, val;
vector<int> M;
vector<int> List;
void Input() {
	cin >> num;
	M.assign(num + 1, 0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		M[tmp] = i;
	}
	cin >> val;
	for (int i = 0; i < val; i++) {
		int tmp;
		cin >> tmp;
		if (M[tmp] > 0)
			List.push_back(tmp);
	}
}

int BinarySearch(vector<int> &v,int key) {
	int st = 0, ed = v.size() - 1, mid = (st + ed) / 2;
	while (st < ed) {
		if (M[v[mid]] <= M[key])
			st = mid + 1;
		else
			ed = mid;
		mid = (st + ed) / 2;
	}
	v[mid] = key;
	return mid;
}

void FavoriteColorStripe() {
	int sz = List.size();
	if (sz == 1) {
		cout << 1;
		return;
	}
	vector<int> vec;
	vec.push_back(List[0]);
	int res = 1;
	for (int i = 1; i < sz; i++) {
		if (M[List[i]] >= M[vec.back()]) {
			vec.push_back(List[i]);
			res = max(res, int(vec.size()));
			
		}
		else {
			int tmp = BinarySearch(vec, List[i]) + 1;
			res = max(tmp, res);
		}
	}
	
	cout << res;
}


int main() {
	Input();
	FavoriteColorStripe();
	//system("pause");
}
