class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> rel;
		vector<int> tmp;
		stack<TreeNode*> lstk;
		stack<TreeNode*> rstk;
		TreeNode* ptr = root;
		int ct = 0;
		if (ptr) {
			tmp.push_back(ptr->val);
			rel.push_back(tmp);
			tmp.clear();
			rstk.push(ptr);
			while (!rstk.empty()||!lstk.empty()) {
				if (ct % 2 == 0) {
					while (!rstk.empty()) {
						ptr = rstk.top();
						rstk.pop();
						if (ptr->right) { tmp.push_back(ptr->right->val); lstk.push(ptr->right); }
						if (ptr->left) { tmp.push_back(ptr->left->val); lstk.push(ptr->left); }
					}
                    if(!tmp.empty()){
					rel.push_back(tmp);
					tmp.clear();}
					ct++;
				}
				else {
					while (!lstk.empty()) {
						ptr = lstk.top();
						lstk.pop();
						if (ptr->left) { tmp.push_back(ptr->left->val); rstk.push(ptr->left); }
						if (ptr->right) { tmp.push_back(ptr->right->val); rstk.push(ptr->right); }
					}
                    if(!tmp.empty()){
					rel.push_back(tmp);
					tmp.clear();}
					ct++;
				}
			}
		}
		return rel;
	}
};
