/*
//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
        if(pslow == NULL || pfast == NULL) //环不存在
            return NULL;
        ListNode *p = pfast;   //相遇结点
        int len =1;
        ListNode *p1 = p->next;
        while(p1 != p) //计算环的长度
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