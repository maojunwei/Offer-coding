/*
��Ŀ������һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        if(pNode->right != NULL) //���¶�
        {
            TreeLinkNode* p = pNode->right;
            while(p->left != NULL)
                p = p->left; 
            return p;
        }
        while(pNode->next != NULL)  //�򸸽�����
        {
            TreeLinkNode* p = pNode->next;
            if(p->left == pNode)
                return p;
            pNode = pNode->next;

        }
        return NULL;
         
    }
};