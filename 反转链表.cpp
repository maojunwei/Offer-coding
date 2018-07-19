/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}//题目要求：结点。反转该链表并输出反转后链表的头结点,类中的return!!!
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
