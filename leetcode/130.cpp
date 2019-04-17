//非递归搜索 正向思路加一个hash表来判断是否需要改变


class Solution {
public:
	void solve(vector<vector<char>>& board) {
	bool hash[1000][1000] = { 0 };
	int row = board.size();
	if (row <= 2) return;
	int col = board[0].size();
	if (col <= 2) return;
	for (int i = 0; i < col; i++) {
		if (board[0][i] == 'O') {
			hash[0][i] = 1;
		}
	}
	for (int i = 0; i < col; i++) {
		if (board[row - 1][i] == 'O') {
			hash[row - 1][i] = 1;
		}
	}
	for (int i = 1; i < row - 1; i++) {
		if (board[i][0] == 'O') {
			hash[i][0] = 1;
		}
	}
	for (int i = 1; i < row - 1; i++) {
		if (board[i][col - 1] == 'O') {
			hash[i][col - 1] = 1;
		}
	}
	for (int i = 1; i < col - 1; i++) {
		if (board[1][i] == 'O' && !hash[1][i]) {
			if (board[0][i] == 'O') {
				stack < pair<int, int >> idx;
				idx.push(pair<int, int>(1, i));
				while (!idx.empty()) {
					pair<int, int> tmp = idx.top();
					idx.pop();
					hash[tmp.first][tmp.second] = 1;
					if (board[tmp.first - 1][tmp.second] == 'O' && !hash[tmp.first - 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first - 1, tmp.second));
					}
					if (board[tmp.first + 1][tmp.second] == 'O' && !hash[tmp.first + 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first + 1, tmp.second));
					}
					if (board[tmp.first][tmp.second - 1] == 'O' && !hash[tmp.first][tmp.second - 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second - 1));
					}
					if (board[tmp.first][tmp.second + 1] == 'O' && !hash[tmp.first][tmp.second + 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second + 1));
					}
				}
			}
		}
	}
	for (int i = 1; i < col - 1; i++) {
		if (board[row - 2][i] == 'O' && !hash[row - 2][i]) {
			if (board[row - 1][i] == 'O') {
				stack < pair<int, int >> idx;
				idx.push(pair<int, int>(row - 2, i));
				while (!idx.empty()) {
					pair<int, int> tmp = idx.top();
					idx.pop();
					hash[tmp.first][tmp.second] = 1;
					if (board[tmp.first - 1][tmp.second] == 'O' && !hash[tmp.first - 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first - 1, tmp.second));
					}
					if (board[tmp.first + 1][tmp.second] == 'O' && !hash[tmp.first + 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first + 1, tmp.second));
					}
					if (board[tmp.first][tmp.second - 1] == 'O' && !hash[tmp.first][tmp.second - 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second - 1));
					}
					if (board[tmp.first][tmp.second + 1] == 'O' && !hash[tmp.first][tmp.second + 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second + 1));
					}
				}
			}
		}
	}
	for (int i = 1; i < row - 1; i++) {
		if (board[i][1] == 'O' && !hash[i][1]) {
			if (board[i][0] == 'O') {
				stack < pair<int, int >> idx;
				idx.push(pair<int, int>(i, 1));
				while (!idx.empty()) {
					pair<int, int> tmp = idx.top();
					idx.pop();
					hash[tmp.first][tmp.second] = 1;
					if (board[tmp.first - 1][tmp.second] == 'O' && !hash[tmp.first - 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first - 1, tmp.second));
					}
					if (board[tmp.first + 1][tmp.second] == 'O' && !hash[tmp.first + 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first + 1, tmp.second));
					}
					if (board[tmp.first][tmp.second - 1] == 'O' && !hash[tmp.first][tmp.second - 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second - 1));
					}
					if (board[tmp.first][tmp.second + 1] == 'O' && !hash[tmp.first][tmp.second + 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second + 1));
					}
				}
			}
		}
	}
	for (int i = 1; i < row - 1; i++) {
		if (board[i][col - 2] == 'O' && !hash[i][col - 2]) {
			if (board[i][col - 1] == 'O') {
				stack < pair<int, int >> idx;
				idx.push(pair<int, int>(i, col-2));
				while (!idx.empty()) {
					pair<int, int> tmp = idx.top();
					idx.pop();
					hash[tmp.first][tmp.second] = 1;
					if (board[tmp.first - 1][tmp.second] == 'O' && !hash[tmp.first - 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first - 1, tmp.second));
					}
					if (board[tmp.first + 1][tmp.second] == 'O' && !hash[tmp.first + 1][tmp.second]) {
						idx.push(pair<int, int>(tmp.first + 1, tmp.second));
					}
					if (board[tmp.first][tmp.second - 1] == 'O' && !hash[tmp.first][tmp.second - 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second - 1));
					}
					if (board[tmp.first][tmp.second + 1] == 'O' && !hash[tmp.first][tmp.second + 1]) {
						idx.push(pair<int, int>(tmp.first, tmp.second + 1));
					}
				}
			}
		}
	}
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			if (board[i][j] == 'O' && !hash[i][j]) {
				board[i][j] = 'X';
			}
		}
	}
}
};

//递归的深度优先搜索
//反向的思路把不要变的标记成其他的字符然后直接递归搜索

class Solution {
public:
   void dfs(vector<vector<char>>& board, int i, int j) {
	int row = board.size();
	int col = board[0].size();
	if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != 'O') return;//递归返回的条件

	board[i][j] = '-';
  //递归的四个方向
	dfs(board, i - 1, j);
	dfs(board, i + 1, j);
	dfs(board, i, j - 1);
	dfs(board, i, j + 1);

}
void solve(vector<vector<char>>& board) {

	if (board.empty()) return;
	int row = board.size();
	int col = board[0].size();

	for (int i = 0; i < row; i++) {
		dfs(board, i, 0);
		dfs(board, i, col - 1);

	}
	for (int i = 0; i < col; i++) {
		dfs(board, 0, i);
		dfs(board, row - 1, i);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == '-') {
				board[i][j] = 'O';
			}
			else {
				board[i][j] = 'X';
			}
		}
	}
}
};
