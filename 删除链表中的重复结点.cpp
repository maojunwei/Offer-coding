/*
��Ŀ����һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) //�����ֻ��һ�����
            return pHead;
        if(pHead->val == pHead->next->val) //��ǰ���Ϊ�ظ����
        {
            ListNode* p = pHead->next;
            while(p!=NULL && p->val == pHead->val) //NUll->data�������壬�ᱨ��
                p = p->next;
            return deleteDuplication(p); //�ӵ�һ�����ظ��Ľ�㿪ʼ�ݹ�
        }
        else
        {
            ListNode* p = pHead->next;
            pHead->next = deleteDuplication(p);  //������ǰ��㣬����һ����㿪ʼ�ݹ�
            return pHead;
        }
    }
};