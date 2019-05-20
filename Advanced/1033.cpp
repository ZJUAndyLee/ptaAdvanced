/*通过贪心算法得到必须经过的加油站路径然后再通过路径得到结果
*贪心算法的主要思路就是：反向思考问题从终点开始寻找在车子能走的范围以内的所以加油站然后再在里面挑出油价最小的加油站 下一次就再从上一个挑选的加油站出发
*如果没有一个某个加油站往前没有加油站了 而且也还没到起点说明走不到终点 这时我们就要记录路径有误然后从起点开始每次都走最大距离得到能走的最大距离
*/

#include<iostream>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

#define DMAX 100000000.0
int V, D, per,Num;

struct gs {
	double price;
	int dis;
	gs(double x, int y) :price(x), dis(y) {};
};

vector<gs> sta;

bool cmp(gs &p1,gs &p2) {
	return p1.dis > p2.dis ? false : true;
}

void Input() {
	cin >> V >> D >> per >> Num;
	for (int i = 0; i < Num; i++) {
		double x;
		int y;
		cin >> x >> y;
		if (y < D)
			sta.push_back(gs(x, y));
	}
}

void ToFillorNottoFill() {
	sort(sta.begin(), sta.end(), cmp);
	int sz = sta.size();
	vector<double> pri(sz, 0.0);
	int total = V * per;
	stack<int> path;
	int pos = D, ct = sz - 1;
	int idx = 1;
	while (pos>0) {
		double min = DMAX;
		int tmp = -1;
		while (ct>=0&&pos - total <= sta[ct].dis) {
			if (sta[ct].price < min) {
				min = sta[ct].price;
				tmp = ct;	
			}
			ct--;
		}
		if (tmp >= 0) {
			pos = sta[tmp].dis;
			path.push(tmp);
		}
		else {
			idx = 0;
			break;
		}
		ct = tmp-1;
	}
	if (idx == 1) {
		int st = 0, dist = 0, rem = 0;
		double res = 0.00;
		int tmppos = path.top();
		while (!path.empty()) {
			tmppos = path.top();
			path.pop();
			if (sta[tmppos].price > sta[st].price) {
				res += (total - rem) * 1.0*sta[st].price / per;
				rem = total - (sta[tmppos].dis - sta[st].dis);
			}
			else {
				res += (sta[tmppos].dis - sta[st].dis - rem)*1.0*sta[st].price / per;
				rem = 0;
			}
			st = tmppos;
		}
		res += (D - sta[tmppos].dis)*1.0*sta[tmppos].price / per;
		printf("%.2f", res);
	}
	else {
		if (sta[0].dis > 0) {
			printf("The maximum travel distance = %.2f", 0.00);
			return;
		}
		double res = sta[0].dis + total, pos = 1;
		while (pos<sz&&res >= sta[pos].dis) {
			res = sta[pos].dis + total;
			pos++;
		}
		printf("The maximum travel distance = %.2f", res);
	}
	
		
	
}

int main() {
	Input();
	ToFillorNottoFill();

}
