/*
题目：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
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
        if(pNode->right != NULL) //向下端
        {
            TreeLinkNode* p = pNode->right;
            while(p->left != NULL)
                p = p->left; 
            return p;
        }
        while(pNode->next != NULL)  //向父结点遍历
        {
            TreeLinkNode* p = pNode->next;
            if(p->left == pNode)
                return p;
            pNode = pNode->next;

        }
        return NULL;
         
    }
};