//对称二叉树
//递归做法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(!root) return true;
      return isM(root->left,root->right);
    }
    bool isM(TreeNode * l,TreeNode *r){
        if(!l&&!r) return true;
        if(!r||!l) return false;
        if(r->val==l->val) return isM(l->left,r->right)&&isM(l->right,r->left);
        return false;
    }
};

//迭代做法：
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root||(!root->left&&!root->right)) return true;
        if(!root->left||!root->right) return false;
        stack<TreeNode *> stkl,stkr;
        TreeNode *tmpl=root->left,*tmpr=root->right;
        int dpl=0,dpr=0;
        while((!stkl.empty()||tmpl)&&(!stkr.empty()||tmpr)){
            while(tmpl){
                stkl.push(tmpl);
                dpl++;
                tmpl=tmpl->left;
            }
            while(tmpr){
                stkr.push(tmpr);
                dpr++;
                tmpr=tmpr->right;
            }
            if(!stkl.empty()&&!stkr.empty()){
                tmpl=stkl.top();
                stkl.pop();
                tmpr=stkr.top();
                stkr.pop();
                if(tmpl->val!=tmpr->val||dpl!=dpr) return false;
                tmpl=tmpl->right;
                tmpr=tmpr->left;
                //if(!tmpl) dpl--;
               // if(!tmpr) dpr--;
            }
        }
        if(stkl.empty()&&stkr.empty()&&!tmpl&&!tmpr) return true;
        return false;
    }
};
