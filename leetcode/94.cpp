//中序遍历循环非递归算法

class Solution {
public:
   vector<int> inorderTraversal(TreeNode* root) {
		TreeNode *ptr = root;
		stack<TreeNode*> stk;
		vector<int> rel;
		while (ptr || !stk.empty()) {
			while (ptr) {
				//rel.push_back(ptr->val);先序遍历
				stk.push(ptr);
				ptr = ptr->left;
			}
			if (!ptr) {
				ptr = stk.top();
				stk.pop();
				rel.push_back(ptr->val);
				ptr = ptr->right;
			}
		}
       return rel;
	}
};

//中序遍历递归算法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        vector<int> left;
        vector<int> right;
        if(root){
            if(root->left)
            {
            left = inorderTraversal(root->left);
            results.insert(results.end(),left.begin(),left.end());
            }
            results.push_back(root->val);
            if(root->right)
            {
                right = inorderTraversal(root->right);
                results.insert(results.end(),right.begin(),right.end());
            }
            return results;
        }
        return results;
        
    }
};
