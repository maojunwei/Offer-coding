/*
��Ŀ����ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
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