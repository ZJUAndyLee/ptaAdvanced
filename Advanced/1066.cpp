/*这道题没有用任何巧妙地方法 直接手写了AVL的插入
* 我们比一般的二叉树多维护两个变量一个是树高h以及父结点par*/



#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;

struct node {//树的结点信息 包括树的左子树，右子树 父结点 树高 以及值
	int h, val;
	node *left, *right;
	node *par;
	node(node *p, int v) :par(p), val(v), h(1), left(NULL), right(NULL) { };
};
typedef node * ptrnode;
void Insert(ptrnode *root, int v) {
	ptrnode ptr = *root;
	ptrnode tmpp = NULL;
	while (true) {//找到需要插入的位置
		if (v < ptr->val) {
			if (ptr->left)
				ptr = ptr->left;
			else {
				ptr->left = new node(ptr, v);
				while (ptr) {//插入之后向上调整树高 并且找到与插入结点最近的被破坏的结点
					int lt = ptr->left ? ptr->left->h : 0;
					int rt = ptr->right ? ptr->right->h : 0;
					if (lt - rt >= 2 || lt - rt <= -2) {
						tmpp = ptr;
						break;
					}
					ptr->h = max(lt, rt) + 1;
					ptr = ptr->par;
				}
				break;
			}
		}
		else {
			if (ptr->right)
				ptr = ptr->right;
			else {
				ptr->right = new node(ptr, v);
				bool first = true;
				while (ptr) {
					int lt = ptr->left ? ptr->left->h : 0;
					int rt = ptr->right ? ptr->right->h : 0;
					if (first && (lt - rt >= 2 || lt - rt <= -2)) {
						tmpp = ptr;
						first = false;
					}
					ptr->h = max(lt, rt) + 1;
					ptr = ptr->par;
				}
				break;
			}
		}
	}
	if (tmpp) {//是否平衡条件被破坏
		if (tmpp->val > v) {
			if (tmpp->left&&tmpp->left->val > v) {//左左旋转
				ptrnode p1 = tmpp;
				ptrnode p2 = tmpp->left;
				p2->par = p1->par;
				p1->par = p2;

				p1->left = p2->right;
				if (p1->left)
					p1->left->par = p1;
				p2->right = p1;
				
				if (p2->par == NULL) {//如果旋转之后的根节点的父结点是NULL说明该根节点就是总的树的根节点
					*root = p2;
				}
				else {
					if (p1 == p2->par->left) {
						p2->par->left = p2;
					}
					else
						p2->par->right = p2;
				}
        //向上调整树高
				int lt = p1->left ? p1->left->h : 0;
				int rt = p1->right ? p1->right->h : 0;
				p1->h = max(lt, rt) + 1;
				while (p2) {
					lt = p2->left ? p2->left->h : 0;
					rt = p2->right ? p2->right->h : 0;
					p2->h = max(lt, rt) + 1;
					p2 = p2->par;
				}
			}
			if (tmpp->left&&tmpp->left->val < v) {//左右旋转
				ptrnode p1 = tmpp;
				ptrnode p2 = tmpp->left;
				ptrnode p3 = tmpp->left->right;
				p3->par = p1->par;

				p2->right = p3->left;
				if (p2->right)
					p2->right->par = p2;
				p3->left = p2;
				p2->par = p3;

				p1->left = p3->right;
				if (p1->left)
					p1->left->par = p1;
				p3->right = p1;
				p1->par = p3;

				if (p3->par == NULL) {
					*root = p3;
				}
				else {
					if (p1 == p3->par->left) {
						p3->par->left = p3;
					}
					else
						p3->par->right = p3;
				}
				int lt = p1->left ? p1->left->h : 0;
				int rt = p1->right ? p1->right->h : 0;
				p1->h = max(lt, rt) + 1;
				lt = p2->left ? p2->left->h : 0;
				rt = p2->right ? p2->right->h : 0;
				p2->h = max(lt, rt) + 1;
				while (p3) {
					lt = p3->left ? p3->left->h : 0;
					rt = p3->right ? p3->right->h : 0;
					p3->h = max(lt, rt) + 1;
					p3 = p3->par;
				}
			}
		}
		else {
			if (tmpp->right&&tmpp->right->val < v) {//右右旋转
				ptrnode p1 = tmpp;
				ptrnode p2 = tmpp->right;
				p2->par = p1->par;
				p1->par = p2;
				p1->right = p2->left;
				if (p1->right)
					p1->right->par = p1;
				p2->left = p1;
				if (p2->par == NULL) {
					*root = p2;
				}
				else {
					if (p1 == p2->par->left) {
						p2->par->left = p2;
					}
					else
						p2->par->right = p2;
				}
				int lt = p1->left ? p1->left->h : 0;
				int rt = p1->right ? p1->right->h : 0;
				p1->h = max(lt, rt) + 1;
				while (p2) {
					lt = p2->left ? p2->left->h : 0;
					rt = p2->right ? p2->right->h : 0;
					p2->h = max(lt, rt) + 1;
					p2 = p2->par;
				}
			}
			else {//右左旋转
				ptrnode p1 = tmpp;
				ptrnode p2 = tmpp->right;
				ptrnode p3 = tmpp->right->left;
				p3->par = p1->par;

				p1->right = p3->left;
				if (p1->right)
					p1->right->par = p1;
				p3->left = p1;
				p1->par = p3;

				p2->left = p3->right;
				if (p2->left)
					p2->left->par = p2;
				p3->right = p2;
				p2->par = p3;

				if (p3->par == NULL) {
					*root = p3;
				}
				else {
					if (p1 == p3->par->left) {
						p3->par->left = p3;
					}
					else
						p3->par->right = p3;
				}
				int lt = p1->left ? p1->left->h : 0;
				int rt = p1->right ? p1->right->h : 0;
				p1->h = max(lt, rt) + 1;
				lt = p2->left ? p2->left->h : 0;
				rt = p2->right ? p2->right->h : 0;
				p2->h = max(lt, rt) + 1;
				while (p3) {
					lt = p3->left ? p3->left->h : 0;
					rt = p3->right ? p3->right->h : 0;
					p3->h = max(lt, rt) + 1;
					p3 = p3->par;
				}
			}
		}
	}

}

void blt(node *r) {
	node *tmp = r;
	if (tmp->left)
		blt(tmp->left);
	cout << tmp->val<<" ";
	if (tmp->right)
		blt(tmp->right);
}

int main() {
	int num;
	cin >> num;
	vector<int> vec;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	ptrnode root = new node(NULL, vec[0]);
	for (int i = 1; i < num; i++) {
		Insert(&root, vec[i]);
		//blt(root);
		//cout << endl;
	}
	cout << root->val<<endl;
	//system("pause");
}
