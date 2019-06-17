class Solution {
public:
   TreeNode* bstFromPreorder(vector<int>& preorder) {
	    if (preorder.empty())
		    return NULL;
	    TreeNode *node = new TreeNode(preorder[0]);
	    int i = 1;
	    while (i < preorder.size() && preorder[i] < preorder[0]) i++;
	    vector<int> lt, rt;
	    if (i > 1) {
		    lt.assign(preorder.begin() + 1, preorder.begin() + i);
	    }
	    if (i < preorder.size()) {
		    rt.assign(preorder.begin() + i, preorder.end());
	    }
	    node->left = bstFromPreorder(lt);
	    node->right = bstFromPreorder(rt);
	    return node;
  }
};
