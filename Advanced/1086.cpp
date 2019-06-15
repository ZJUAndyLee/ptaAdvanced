//根据先序以及中序遍历得到完整的二叉树，然后递归得到后序遍历

#include <iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

struct node {
	int val;
	node *lt, *rt;
	node(int x) :val(x), lt(NULL), rt(NULL) {};
};

node *creatTree(vector<int> &prev,vector<int> &inv) {
	if (prev.empty())
		return NULL;
	int root = prev[0];
	node *ptr = new node(root);
	int pos = 0;
	while (pos < inv.size()) {
		if (inv[pos] == root)
			break;
		pos++;
	}
	int lt = pos, rt = inv.size() - pos - 1;
	if (lt > 0) {
		vector<int> ltpre(prev.begin() + 1, prev.begin() + pos + 1);
		vector<int> ltin(inv.begin(), inv.begin() + pos);
		ptr->lt = creatTree(ltpre, ltin);
	}
	if (rt > 0) {
		vector<int> rtpre(prev.begin() + pos + 1, prev.end());
		vector<int> rtin(inv.begin() + pos + 1, inv.end());
		ptr->rt = creatTree(rtpre, rtin);
	}
	return ptr;
}

void postOrder(node *ptr,int ct) {
	if (ptr->lt)
		postOrder(ptr->lt, ct++);
	if (ptr->rt)
		postOrder(ptr->rt, ct++);
	if (ct != 0)
		cout << " " << ptr->val;
	else {
		cout << ptr->val;
	}
}

int main() {
	int num;
	scanf("%d", &num);
	int ct = 0;
	stack<int> stk;
	vector<int> pre, in;
	while (ct < num) {
		string str;
		cin >> str;
		if (str[1] == 'u') {
			int tmp;
			cin >> tmp;
			stk.push(tmp);
			pre.push_back(tmp);
			ct++;
		}
		else {
			in.push_back(stk.top());
			stk.pop();
		}
	}
	while (!stk.empty()) {
		in.push_back(stk.top());
		stk.pop();
	}
	node *root = creatTree(pre, in);
	postOrder(root, 0);

}
