//非递归实现二叉搜索树的先序遍历 即可得到一个从小到大的数组，然后再通过这个数组得到相差最小的两个点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		stack<TreeNode *> stk;
		TreeNode *tmp = root;
		int numlt = -1, numw = -1, min = INT_MAX;
		while (!stk.empty() || tmp) {
			while (tmp) {
				stk.push(tmp);
				tmp = tmp->left;
			}
			if (!stk.empty()) {
				tmp = stk.top();
				stk.pop();
				if (numlt < 0) {
					numlt = tmp->val;
				}
				else {
					numw = tmp->val;
					min = numw - numlt < min ? numw - numlt : min;
					numlt = numw;
				}
				tmp = tmp->right;
			}
		}
	}
};
