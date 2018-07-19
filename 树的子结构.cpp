/*
题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
      if(pRoot1 == NULL || pRoot2 == NULL)
          return false;
      return HasSub(pRoot1, pRoot2) || HasSubtree(pRoot1->right, pRoot2) || HasSubtree(pRoot1->left, pRoot2);
    }
    bool HasSub(TreeNode* proot1, TreeNode* proot2)
    {
        if(!proot2)
            return true;
        if(!proot1)
            return false;
        if(proot1->val != proot2->val)
            return false;
        return HasSub(proot1->left, proot2->left)&& HasSub(proot1->right, proot2->right);
         
         
    }
};