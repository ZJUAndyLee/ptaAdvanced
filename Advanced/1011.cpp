#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void Input(vector<vector<double>> &g) {
	for (int i = 0; i<3; i++) {
		vector<double> tmp;
		for (int j = 0; j<3; j++) {
			double tmpD;
			cin >> tmpD;
			tmp.push_back(tmpD);
		}
		g.push_back(tmp);
	}
}

void Betting(vector<vector<double>> &g) {
	double maxD[3];
	for (int i = 0; i<3; i++) {
		if (g[i][0]>g[i][1] && g[i][0]>g[i][2]) {
			maxD[i] = g[i][0];
			cout << "W" << " ";
		}
		if (g[i][1]>g[i][0] && g[i][1]>g[i][2]) {
			maxD[i] = g[i][1];
			cout << "T" << " ";
		}
		if (g[i][2]>g[i][0] && g[i][2]>g[i][1]) {
			maxD[i] = g[i][2];
			cout << "L" << " ";
		}
	}
	double res = (maxD[0] * maxD[1] * maxD[2] * 0.65 - 1) * 2;
	cout << fixed << setprecision(2) << res  ;
}

int main() {
	vector<vector<double>> vec;
	Input(vec);
	Betting(vec);

}
