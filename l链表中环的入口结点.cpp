/*
//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        ListNode *pslow = pHead->next;
        ListNode *pfast = pHead;
        while(pslow != NULL && pfast != NULL && pslow != pfast)
        {
            pslow = pslow->next;
            pfast = pfast->next;
            if(pfast->next != NULL)
                pfast = pfast->next;
        }
        if(pslow == NULL || pfast == NULL) //��������
            return NULL;
        ListNode *p = pfast;   //�������
        int len =1;
        ListNode *p1 = p->next;
        while(p1 != p) //���㻷�ĳ���
        {
            p1 = p1->next;
            len++;
        }
        ListNode *pre = pHead;
        ListNode *pend = pHead;
        for(int i=0;i<len;i++)
            pend = pend->next;
        while(pre != pend)
        {
            pre = pre->next;
            pend = pend->next;           
        }
        return pre;
    }
};