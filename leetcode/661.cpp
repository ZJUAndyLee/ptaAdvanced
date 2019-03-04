//用时336ms很慢 关键的速度损耗应该在计算和判断的位置

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int> >& vec) {
        int tmp;
        int ct=0;
        vector<vector<int>> m;
	    vector<int> pool;
	    int row = vec.size();
        int col = vec[0].size();
        for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			tmp = 0;
            ct=0;
			if (i - 1 >= 0) {
				tmp += vec[i - 1][j];ct++;
				if (j - 1 >= 0) {tmp += vec[i - 1][j - 1];ct++;}
				if (j + 1 < col){tmp += vec[i - 1][j + 1];ct++;}
			}
			if (j - 1 >= 0) {tmp += vec[i][j - 1];ct++;}
			if (j + 1 < col) {tmp += vec[i][j + 1];ct++;}
			if (i + 1 < row) {
				tmp += vec[i + 1][j];ct++;
				if (j - 1 >= 0){tmp += vec[i + 1][j - 1];ct++;}
				if (j + 1 < col){tmp += vec[i + 1][j + 1];ct++;}
			}
			tmp += vec[i][j];ct++;
			pool.push_back(tmp / ct);
		}
            m.push_back(pool);
            pool.clear();
	}
	
    return m;
    }
};
