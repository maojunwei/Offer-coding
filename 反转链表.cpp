/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}//��ĿҪ�󣺽�㡣��ת�����������ת�������ͷ���,���е�return!!!
};*/
class Solution {
public:
        ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead ->next == NULL)
            return pHead;
        ListNode *pre,*after,*p;
        pre = NULL;
        p = pHead;
        while(p != NULL)
        {
            after = p->next;
            p->next = pre;
            if(after == NULL)
            {
                return p;
            }
            pre = p;
            p = after;
        }
    }
    };
    /*
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        if(pHead ->next == NULL)
            return pHead;
        ListNode *pre,*after,*p;
        pre = NULL;
        p = pHead->next;
        while(p != NULL)
        {
            after = p->next;
            p->next = pre;
            if(p->next == NULL)
            {
                pHead->next = p;
                return pHead;
            }
            pre = p;
            p = after;
        }
    }
    */
