//由于分镜像和正常二叉树所以把这两种情况分开来了 首先利用递归将先序遍历转化为二叉搜索树 然后通过中序遍历来判断是否是一颗二叉搜索树 最后再通过后序遍历来输出二叉树

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

#define IMAX 2147483647
#define IMIN -2147483648

using namespace std;
int num;
struct node {
	int key;
	node *left;
	node *right;
	node(int val) :key(val), left(NULL), right(NULL) {};
};

vector<int> arr;

void Input() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
}

node *BuiltTree1(vector<int> &v) {
	if (v.size() == 0)
		return NULL;
	else if (v.size() == 1) {
		node *ptr = new node(v[0]);
		return ptr;
	}
	node *ptr = new node(v[0]);
	vector<int> rt, lt;
	int i = 1;
	for (; i < v.size(); i++) {
		if (v[i] < v[0])
			lt.push_back(v[i]);
		else
			break;
	}
	for (; i < v.size(); i++)
		rt.push_back(v[i]);
	ptr->left = BuiltTree1(lt);
	ptr->right = BuiltTree1(rt);
	return ptr;
}

void postOrder(node *root,node *idx) {
	if(root->left)
		postOrder(root->left,idx);
	if (root->right)
		postOrder(root->right,idx);
	if (root == idx)
		cout << root->key;
	else
		cout << root->key << " ";
}

node *BuiltTree2(vector<int> &v) {
	if (v.size() == 0)
		return NULL;
	else if (v.size() == 1) {
		node *ptr = new node(v[0]);
		return ptr;
	}
	node *ptr = new node(v[0]);
	vector<int> rt, lt;
	int i = 1;
	for (; i < v.size(); i++) {
		if (v[i] >= v[0])
			lt.push_back(v[i]);
		else
			break;
	}
	for (; i < v.size(); i++) {
		rt.push_back(v[i]);
	}
	ptr->left = BuiltTree2(lt);
	ptr->right = BuiltTree2(rt);
	return ptr;
}

void BinarySearchTree() {
	if (arr.size() > 1) {
		int idx = 1;
		node *root;
		if (arr[1] < arr[0]) {
			root = BuiltTree1(arr);
			node *ptr = root;
			stack<node *> stk;
			int tmpi = -IMIN;
			while (ptr || !stk.empty()) {
				while (ptr) {
					stk.push(ptr);
					ptr = ptr->left;
				}
				if (!stk.empty()) {
					node *tmpp = stk.top();
					stk.pop();
					
					if (tmpp->key < tmpi) {
						idx = 0;
						break;
					}
					ptr = tmpp->right;
					tmpi = tmpp->key;
				}
			}
		}
		else {
			root = BuiltTree2(arr);
			node *ptr = root;
			stack<node *> stk;
			int tmpi = IMAX;
			while (ptr || !stk.empty()) {
				while (ptr) {
					stk.push(ptr);
					ptr = ptr->left;
				}
				if (!stk.empty()) {
					node *tmpp = stk.top();
					stk.pop();
					if (tmpp->key > tmpi) {
						idx = 0;
						break;
					}
					ptr = tmpp->right;
					tmpi = tmpp->key;
				}
			}
		}
		if (idx == 0) {
			cout << "NO";
		}
		else {
			cout << "YES" << endl;
			postOrder(root,root);
		}

	}
	else {
        cout<<"YES"<<endl;
		cout << arr[0];
	}

}

int main() {
	Input();
	BinarySearchTree();
	//system("pause");
}
