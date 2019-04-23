//这个题真的是用到了 DFS的精髓 主要思路就是每个字母遍历然后 判断以这个字母为消除起点去做消除如果能消除那么比较每个字母为起点的一个消除步骤大小 返回一个最小值

class Solution {
public:
	unordered_map<char, int> times;//这是一个全局变量用来记录手上有多少个球
	void elim(string &str, int pos) {//这个函数用来做自消除操作
		int start = pos;
		for (; start >= 0 && str[start] == str[pos]; start--);//主要是看str从当前位置往前有没有相同的字母 因为后面的字母会在dfs的递归中遍历到
		if (pos - start == 1) return;//如果后面一个字母不相同直接返回
		int end = pos;
		for (; end < str.size() && str[end] == str[pos]; end++);
		if (end - start - 1 >= 3) {//只有当相邻的相同字母的个数达到3个或以上才会进行消除
			str.erase(start + 1, end - start - 1);//将相邻的字符抹去
			elim(str, start + 1);//递归调用elim继续看是否有消除的可能  因为不停在消除所以注意pos的值
		}

	}

	int dfs(string &board, int balls) {
		if (board.empty()) return 0;//消除完毕 返回球的需求数为0
		if (balls == 0) return -1;//当没有球了 而且board不为空的话则返回-1
		int sz = board.size();
		int ct = 0;
		int dpt = INT_MAX;//dpt为当前循环里的需求的球数
		for (int i = 0; i < sz; i++) {
			ct++;
			if ( i==sz-1 ||board[i + 1] != board[i]) {
				if (times[board[i]] + ct >= 3) {//如果手中有的球能满足消除条件
					times[board[i]] = times[board[i]] - 3 + ct;//手中的该类球相应减少
					string tmp = board;//将board复制
					tmp.erase(i - ct + 1, ct);//把和手上的球匹配的球消除
					elim(tmp, i - ct + 1);//然后尽可能的对tmp做减法
					int res = dfs(tmp, balls - (3 - ct));//dfs递归tmp
					if (res != -1) {//如果res=-1那么说明当前点不能消除完
						dpt = min(dpt, res + (3 - ct));//然后取整个遍历下来的最小值
					}
					times[board[i]] = times[board[i]] + 3 - ct;//再将手中的球复原以便下一个点的遍历
				}
				ct = 0;//重复计数也归零
			}
		}
		return dpt == INT_MAX ? -1 : dpt;//判断dpt是否改变过 没有说明这个board的每个点遍历下来都无法消除玩直接返回-1 否则就返回最小的球数
	}
	int findMinStep(string board, string hand) {
		for (auto x : hand) {//初始化手上球的散列表
			times[x]++;
		}
		return dfs(board, hand.size());//直接返回dfs的值
	}
};
