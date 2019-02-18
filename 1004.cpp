//BFS方法比较容易可以得到结果
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

struct node {
	int num;
	node *p;
};

struct tree {
	node *cd;
	int n, m;
};

int s_toi(string str) {
	int num=0;
	num = (str[0] - '0') * 10 + (str[1] - '0');
	return num;
}

node *bdnode(int n) {
	node *ptr = new node;
	ptr->num = n;
	ptr->p = NULL;
	return ptr;
}

void bdtree(tree *t,int n,int m) {
	string tmp1,tmp2;
	int k,num;
	node *ptr;
	for (int i = 0; i < n; i++) t[i].cd = NULL;
	for (int i = 0; i < m; i++) {
		cin >> tmp1 >> k;
		num = s_toi(tmp1);
		for (int j = 0; j < k; j++) {
			cin >> tmp2;
			if (!t[num].cd) t[num].cd = bdnode(s_toi(tmp2));
			else {
				ptr = t[num].cd;
				while (ptr->p) ptr = ptr->p;
				ptr->p = bdnode(s_toi(tmp2));
			}
		}
	}
}

void BFS(tree *t) {
	int tmp=0,i=0,nd;
	node *ptr = t[1].cd;
	queue<int> qe;
	qe.push(1);
	if (!t[1].cd) {
		cout << 1;
		return;
	}	
	tmp = t[1].cd->num;
	while (!qe.empty()) {
		nd = qe.front();
		qe.pop();
		ptr = t[nd].cd;
		while (ptr) {
			if (tmp == ptr->num) {
				cout << i << " ";
				i = 0;
				if (!t[ptr->num].cd) tmp = 0;
				else tmp = t[ptr->num].cd->num;
			}
			if (!t[ptr->num].cd) { i++;  }
			else if (tmp == 0) tmp = t[ptr->num].cd->num;
			qe.push(ptr->num);
			ptr = ptr->p;
		}
		
	}
	cout << i;
	return;
}

int main(){
	int n,m;
	string x;
	tree *ft;
	cin >> n >> m;
	ft = new tree[n+1];
	bdtree(ft,n+1,m);
	BFS(ft);
}
