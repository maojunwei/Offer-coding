/*
��Ŀ��
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {   //�����������
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