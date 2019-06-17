class Solution {
public:
	bool cutTree(TreeNode *node) {
		bool lt = false;
		bool rt = false;
		if (node->left) {
			lt = cutTree(node->left);
			if (!lt)
				node->left = NULL;
		}
		if (node->right) {
			rt = cutTree(node->right);
			if (!rt)
				node->right = NULL;
		}
		if (node->val == 1)
			return true;
		else
			return false || lt || rt;
	}

	TreeNode* pruneTree(TreeNode* root) {
		if (!root)
			return NULL;
		if (cutTree(root))
			return root;
		return NULL;
	}
};
