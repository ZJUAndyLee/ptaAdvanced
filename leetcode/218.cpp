//这个题的主要思想就是把连续的问题离散化 每次用最短线段去遍历所有线段找到分段所在 关键点在于结束循环的控制以及跳跃点的处理

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
	vector<pair<int, int>> res; 
	//sort(buildings.begin(), buildings.end(), my_less);
	if (buildings.empty()) return res;
	else if (buildings.size() == 1) {
		pair<int, int> tmp_p1(buildings[0][0], buildings[0][2]); pair<int, int> tmp_p2(buildings[0][1], 0);
		res.push_back(tmp_p1); res.push_back(tmp_p2);
		return res;
	}
	vector<int> tmp = buildings[0]; vector<int> nextv = tmp;
	int ct = 0;
	int s_min = buildings[0][0], s_max = buildings[0][1];
	for(int i=1;i<buildings.size();i++){
		if (s_max < buildings[i][1]) { s_max = buildings[i][1]; }
	}
	while(1){
		for (int i = 0; i < buildings.size(); i++) {
			if (buildings[i][0] < tmp[1]&&buildings[i][1]>tmp[0]) {
				if (buildings[i][2] > tmp[2]) {
					if (tmp[0] == buildings[i][0]) {
						tmp = buildings[i]; nextv = buildings[i];//这个是为了防止遇到 1，2，1  1，2，2  1，2，3这种数组
					}
					else if(tmp[0]< buildings[i][0]){
						tmp[1] = buildings[i][0]; nextv = buildings[i];
					}
					else {
						if (buildings[i][1] >= tmp[1]) {
							tmp[1] = buildings[i][1];
							tmp[2] = buildings[i][2];
							nextv[0] = nextv[1] = buildings[i][1];
							nextv[2] = buildings[i][2];
						}
						else {
							nextv[0] = buildings[i][1]; nextv[1] = tmp[1]; nextv[2] = tmp[2];
							tmp[1] = buildings[i][1];
							tmp[2] = buildings[i][2];
						}
					}
				}
				else if (buildings[i][2] < tmp[2]) {
					if (buildings[i][1] > tmp[1]) { nextv[0] = tmp[1]; nextv[1] = buildings[i][1]; nextv[2] = buildings[i][2]; }
				}
			}
		}//前面的循环相当于去找到最短单元线段 前提是遍历的线段必须有交集
		pair<int, int> tmp_p;
		tmp_p.first = tmp[0]; tmp_p.second = tmp[2];
		if (res.empty())  res.push_back(tmp_p); 
		else {
			if (tmp_p.first!=res.back().first&&tmp[0]!=tmp[1]) res.push_back(tmp_p); //压入的结果必须要满足两点 即：开头不与前面的相等，结果线段的开头和结尾不能相等
		}
		if (tmp[0] == nextv[0] && tmp[1] == nextv[1] && tmp[2] == nextv[2]) {//处理跳跃点
			ct++;
			if (ct==1) {
				for (int i = 0; i < buildings.size(); i++) {
					if (buildings[i][0] > tmp[1]) {
						pair<int, int> tmp_p;
						tmp_p.first = tmp[1]; tmp_p.second = 0; res.push_back(tmp_p); 
						nextv = buildings[i]; ct = 0 ;  break;
					}
					else if (buildings[i][0] == tmp[1]) {
						if (tmp[2] == buildings[i][2]) { nextv[0] = tmp[0]; nextv[1] = buildings[i][1]; nextv[2] = tmp[2]; ct = 0; break; }
						else { nextv = buildings[i]; ct = 0; break; }
					}
				}
			}
			else break;
		}
		tmp = nextv;
	}
	pair<int, int> tmp_p;
	tmp_p.first = s_max; tmp_p.second = 0; res.push_back(tmp_p);//将最后个点压入
	return res;
}
