//二叉树层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode * tmp=root;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        vector<int> cls;
        if(!root) return res;
        while(!q.empty()){
            TreeNode *td = q.front();
            q.pop();
            if(td==tmp||!tmp){//树深度的判断
                if(tmp){
                    if(!cls.empty()) res.push_back(cls);
                    cls.clear();
                    tmp=NULL;
                }
                if(td->left) {
                    tmp=td->left;
                }
                if(td->right){
                    if(!tmp) tmp=td->right;
                }
            }
            cls.push_back(td->val);
             if(td->left) {
                q.push(td->left);
            }
            if(td->right){
                q.push(td->right);
            }
        }
        if(!cls.empty()) res.push_back(cls);
        return res;
    }
};
