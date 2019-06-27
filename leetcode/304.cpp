//类似于动态规划 先把列的累加或者行的累加算好 再去继续算具体的矩阵之和
class NumMatrix {
public:
	vector<vector<int>> mat1;
	int row, col;
	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) {
			row = 0, col = 0;
		}
		else {
			row = matrix.size();
			col = matrix[0].size();
			for (int i = 0; i < row; i++) {
				vector<int> tmpv;
				int tmps = 0;
				for (int j = 0; j < col; j++) {
					tmps += matrix[i][j];
					tmpv.push_back(tmps);
				}
				mat1.push_back(tmpv);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int res = 0;
		if (row > 0) {
			for (int i = row1; i <= row2; i++) {
				if (col1 > 0) {
					res += mat1[i][col2] - mat1[i][col1 - 1];
				}
				else {
					res += mat1[i][col2];
				}
			}
		}
		return res;
	}
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
