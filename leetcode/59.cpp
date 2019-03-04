//该版本用16ms 问题主要出现在判断上下 左右时运用了过多了判断 而且还把数组给初始赋值了 其实只需要考虑四种形式的演化 即左到右 右到左 上到下 下到上即可

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> p(n, vector<int>(n));
	int jter = 0, iter = 0;
	int tmp_1 = 0;
	int i = 1;
	while (i <= n*n) {
		if (!tmp_1) {
			while (jter - 1 >= 0 && !p[iter][jter - 1]) {
				p[iter][jter] = i++;
				jter--;
			}
			while (jter + 1 < n && !p[iter][jter + 1]) {
				p[iter][jter] = i++;
				jter++;
			}
			p[iter][jter] = i++;
			if (iter - 1 >= 0 && !p[iter - 1][jter]) iter--;
			if (iter + 1 < n && !p[iter + 1][jter]) iter++;
			tmp_1 = 1;
		}
		else {
			while (iter - 1 >= 0 && !p[iter - 1][jter]) {
				p[iter][jter] = i++;
				iter--;
			}
			while (iter + 1 < n && !p[iter + 1][jter]) {
				p[iter][jter] = i++;
				iter++;
			}
			p[iter][jter] = i++;
			if (jter - 1 >= 0 && !p[iter][jter - 1]) jter--;
			if (jter + 1 < n && !p[iter][jter + 1]) jter++;
			tmp_1 = 0;
		}
		
	}
	return p;
}
};


//这是4ms的版本：
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vec(n, vector<int>(n));
        
        int c = 1, j = 0;
        while(c <= n*n)
        {
    
            for(int i = j; i < n - j; i++)//右到左
                vec[j][i] = c++;
            for(int i = j + 1; i < n - j; i++) //上到下
                vec[i][n-j-1] = c++;
            for(int i = n - j - 2; i >= j; i--)//左到右
                vec[n-j-1][i] = c++;
            for(int i = n - j - 2; i > j; i--)//下到上
                vec[i][j] = c++;
            
            j++;
        }
        
        return vec;
    }
};
