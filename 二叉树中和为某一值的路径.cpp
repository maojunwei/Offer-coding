/*
题目：
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {   //深度优先搜索
    vector<vector<int> > vec;
    vector<int> v;
    void dfs(TreeNode* pnode,int number)
    {
        if(pnode)
        {
            v.push_back(pnode->val);
            if(pnode->val - number ==0 && pnode->left == NULL && pnode->right == NULL)
            {               
                vec.push_back(v);
            }
            if(pnode->left)
                dfs(pnode->left,number - pnode->val);
            if(pnode->right)
                dfs(pnode->right,number - pnode->val);           
        }
        v.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        dfs(root,expectNumber);
        return vec;
    }
 
};