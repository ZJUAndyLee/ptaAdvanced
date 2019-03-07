//该题其实就是柱状图最大矩形面积的二维版本 一定要充分熟悉基本的算法才能清晰的写出好的算法

class Solution {
public:
   struct bar {
	bar(int x, int y) :hei(x), index(y) {}
	bar() { hei = -1; index = -1; }
	int hei, index;
};

int maximalRectangle(vector<vector<char>> &matrix) {
	if (matrix.empty()) return 0;
	int row = matrix[0].size();
	int val = 0, tmp_max, max = 0, result = 0;
	vector<bar> stk;
	vector<char> xx;
	for (int i = 0; i < row; i++)  xx.push_back('0');
	matrix.push_back(xx);
	int col = matrix.size();
	bar tmp;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col;) {
			if (!val) {
				for (int k = i; k < row; k++) {
					if (matrix[j][k] == '1')val++;
					else break;
				}
			}

			if (stk.empty() || val >= stk.back().hei) {
				stk.push_back(bar(val, j));
				val = 0;
				j++;
			}
			else {
				tmp = stk.back();
				stk.pop_back();
				tmp_max = tmp.hei*(stk.empty() ? j : (j - stk.back().index - 1));//由于最小值是0，所以当有0进入栈中之后它不会被pop出来所以只要考虑
        //是否栈为空 如果是空的那么长度就等于整个数组的指标如果不是空的 长度等于要计算的值被pop出来之后 数组指标 减去栈的最后一个的值对应的数组指标
        //再减1
				max = tmp_max > max ? tmp_max : max;
			}
		}
        stk.clear();//由于这是一个二维方法 所以每次都需要对单次计算 所用的stack进行clear() 这里最好写一个函数 可能clear()函数比较耗时
	}
	return max;
}
};
