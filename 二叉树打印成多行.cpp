/*
��Ŀ�����ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
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
            while(!q.empty())
            {
                int lv=0;
                int ls = q.size();
               vector<int> v;
                while(lv < ls)
                {
                    TreeNode* p = q.front();
                    cout<<p->val<<' ';
                    v.push_back(p->val);
                    q.pop();
                    lv++;
                    if(p->left)
                        q.push(p->left);
                    if(p->right)
                        q.push(p->right);
                }
                cout<<endl;
                vec.push_back(v);               
            }     
            return vec;
        }
     
};