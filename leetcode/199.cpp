//考察的是层序遍历 我的方法还是老样子直接用队列来做广度优先搜索,用一个栈把遍历的值都存下来 然后标记每层第一个指针当遍历到这个指针时我只要把栈顶的值记录成结果即可

class Solution {
public:
   vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode *> q;
		vector<int> res;
		if (!root) return res;
		q.push(root);
		TreeNode *idx = root;
		stack<int> stk;
		int i = 0;
		while (!q.empty()) {
			TreeNode *tmpN = q.front();
			q.pop();
			if (tmpN == idx||i==0) {
				if(i){
					res.push_back(stk.top());
					i = 0;
				}
				if (tmpN->left) {
					idx = tmpN->left;
					i = 1;
				}
				else if (tmpN->right) {
					idx = tmpN->right;
					i = 1;
				}
			}
			if (tmpN->left) {
				q.push(tmpN->left);
			}
			if (tmpN->right) {
				q.push(tmpN->right);
			}
			stk.push(tmpN->val);
		}
		res.push_back(stk.top());
		return res;
	}
};
//还有一个比较巧妙地递归的做法：
class Solution {
public:
    void findR(vector<int> &res,int tmpN,int &depth,TreeNode *p){
        if(!p) return;
        if(tmpN==depth){
            depth++;
            res.push_back(p->val);
        }
        findR(res,tmpN+1,depth,p->right);
        findR(res,tmpN+1,depth,p->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int dpt=0;
        findR(res,0,dpt,root);
        return res;
    }
};
