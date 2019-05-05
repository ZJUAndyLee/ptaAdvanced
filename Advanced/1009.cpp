#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;

int sz;

struct poly {
	int exp;
	double coe;
	poly *n;
	poly(int e, double c) :exp(e), coe(c), n(NULL) {};
	poly() :n(NULL) {};
};

void Input(vector<pair<int,double>> &A) {
	int tmp;
	cin >> tmp;
	for (int i = 0; i < tmp; i++) {
		int tmpI;
		double tmpD;
		cin >> tmpI >> tmpD;
		A.push_back(pair<int, double>(tmpI, tmpD));
	}
}

void pofp(vector<pair<int, double>> &A, vector<pair<int, double>>& B) {
	poly *res = new poly(0, 0);
	for (int i = 0; i < A.size(); i++) {
		poly *root = new poly;
		poly *tmp = root;
		for (int j = 0; j < B.size(); j++) {
			if (j == 0) {
				tmp->exp = A[i].first + B[j].first;
				tmp->coe = A[i].second*B[j].second;
			}
			else {
				poly *node = new poly(A[i].first + B[j].first, A[i].second*B[j].second);
				tmp->n = node;
				tmp = tmp->n;
			}
		}
		if (i == 0) 
			res = root;
		else {
			poly *p1 = res, *p2 = root;
			while (p1->n&&p2) {
				if (p1->n->exp == p2->exp) {
					p1->n->coe += p2->coe;
					if (p1->n->coe == 0.0)
						p1->n = p1->n->n;
					p2 = p2->n;
				}
				else if (p1->n->exp > p2->exp) {
					p1 = p1->n;
				}
				else {
					poly *ptr = new poly(p2->exp, p2->coe);
					ptr->n = p1->n;
					p1->n = ptr;
					p1 = p1->n;
					p2 = p2->n;
				}
			}
			while (p2) {
				poly *ptr = new poly(p2->exp, p2->coe);
				p1->n = ptr;
				p2 = p2->n;
				p1 = p1->n;
			}
		}
	}
	poly *tmpres = res; 
	int num = 0;
	while (tmpres) {
		num++;
		tmpres = tmpres->n;
	}
	cout << num ;
	while (res) {
		cout << " " << res->exp << " " <<fixed<<setprecision(1)<< res->coe;
		res = res->n;
	}
}

int main() {
	vector<pair<int, double>> py1, py2;
	Input(py1);
	Input(py2);
	pofp(py1, py2);

}
