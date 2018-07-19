/*
操作给定的二叉树，将其变换为源二叉树的镜像。
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;   
        /*递归实现
        TreeNode *p;
        p = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = p;     
        Mirror(pRoot->left);
        Mirror(pRoot->right);*/
        /*非递归实现*/
       queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty())
        {
            TreeNode *p1 = q.front();
            q.pop();
            TreeNode *p;
            p = p1->left;
            p1->left = p1->right;
            p1->right = p;
            if(p1->left)
                q.push(p1->left);
            if(p1->right)
                q.push(p1->right);
        }
    }
};