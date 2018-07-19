/*
��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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