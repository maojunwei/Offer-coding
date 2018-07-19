/*
题目：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vec;
        if(pRoot == NULL)
            return vec;
        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 1;
        int le,lq;
        while(!q.empty())
        {
            vector<int> v;
            int le = 0;
            int lq = q.size();           
            while(le < lq)
            {
                TreeNode* p = q.front();
                v.push_back(p->val);
                le++;
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            if(level % 2 == 0)
            {
                std::reverse(v.begin(),v.end());
            }
            level++;
            vec.push_back(v);
        }
        return vec;
    }
};