/**题目描述：满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。

返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。

答案中每个树的每个结点都必须有 node.val=0。

你可以按任何顺序返回树的最终列表。
*/

/** 这是一个典型的递归的问题 对于一颗满二叉树它的左子树和右子树也必定是一颗满二叉树 由于函数返回的是所有可能的满二叉树的根节点所以这里可以实现递归
而边界条件就是当节点数为1的时候返回一个单节点即可 注意当节点个数是偶数是是无法得到一颗满二叉树的
*/
class Solution {
public:
   vector<TreeNode*> allPossibleFBT(int N) {
	vector<TreeNode*> res;
	if (N % 2 == 0) {
		return res;
	}
	if (N == 1) {
		TreeNode *ptr = new TreeNode(0);
		res.push_back(ptr);
		return res;
	}
	for (int i = 1; i < N; i += 2) {
		vector<TreeNode *> left = allPossibleFBT(i);//左子树所有可能的情况
		vector<TreeNode *> right = allPossibleFBT(N-1-i);//右子树所有可能的情况
		for (TreeNode *l : left) {//而这些可能的情况又可以全部组合起来形成我们的结果
			for (TreeNode *r : right) {
				TreeNode *root = new TreeNode(0);
				root->left = l;
				root->right = r;
				res.push_back(root);
			}
		}
	}
	return res;
}
};
