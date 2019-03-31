//二叉树后序遍历

class Solution {
public:
   vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		vector<int> left;
		vector<int> right;
		if (root) {
      //res.push_back(root->val);前序遍历
			if (root->left) {
				left = postorderTraversal(root->left);
				res.insert(res.end(), left.begin(), left.end());
			}
      //res.push_back(root->val); 中序遍历
			if (root->right) {
				right = postorderTraversal(root->right);
				res.insert(res.end(), right.begin(), right.end());
			}
			res.push_back(root->val);
		}
		return res;
	}
};


//后序遍历的迭代版本 非递归
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *>stk;
		TreeNode *tmp = root;
		stk.push(tmp); stk.push(tmp);
        if(!tmp) return res;
		while (!stk.empty()) {
			tmp = stk.top();
			stk.pop();
			if (!stk.empty()&&tmp==stk.top()) {
				if (tmp->right) { stk.push(tmp->right); stk.push(tmp->right); }
				if (tmp->left) { stk.push(tmp->left); stk.push(tmp->left); }
			}
			else {
				res.push_back(tmp->val);
			}
		}
		return res;
	}
};
