//写了两个中序遍历的版本 一个是循环一个是递归两个时间差不多

//循环版本：
int rangeSumBST(TreeNode* root, int L, int R) {
		TreeNode *tmp = root;
		stack<TreeNode *> stk;
		int res = 0;
		while (tmp || !stk.empty()) {
			while (tmp) { 
				stk.push(tmp);
				tmp = tmp->left;
			}
			if (!stk.empty()) {
				tmp = stk.top();
				stk.pop();
				if (tmp->val >= L && tmp->val <= R) {
					res += tmp->val;
				}
				else if (tmp->val > R) break;
				tmp = tmp->right;
			}
		}
		return res;
	}
  
  //递归版本：
  int rangeSumBST(TreeNode* root, int L, int R) {
		int ct = 0;
		if (root) {
			if (root->left) {
				ct += rangeSumBST(root->left, L, R);
			}
			if (root->val >= L && root->val <= R) {
				ct += root->val;
			}
			if (root->right) {
				ct += rangeSumBST(root->right, L, R);
			}
		}
		return ct;
	}
