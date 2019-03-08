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
