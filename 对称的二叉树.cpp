/*
题目：请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
         
        return issametree(pRoot,pRoot);
    }
    /*
    TreeNode* pRoot1 = pRoot;
        mirro(pRoot1);      //pRoot1与pRoot，同一地址，都被镜像
    void mirro(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return;
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        mirro(pRoot->left);
        mirro(pRoot->right);       
    }*/
    bool issametree(TreeNode* pRoot,TreeNode* pRoot1)
    {
        if(pRoot==NULL && pRoot1==NULL)
            return true;
        if(pRoot==NULL || pRoot1==NULL)
            return false;
         if(pRoot->val != pRoot1->val)
            return false;
        return issametree(pRoot->left,pRoot1->right) && issametree(pRoot->right,pRoot1->left);
         
         
    }
};
添加笔记
