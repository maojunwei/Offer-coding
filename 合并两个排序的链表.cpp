/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//方法一：
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead;
        if(pHead2 == NULL )
            return pHead1;
        if(pHead1 == NULL )
            return pHead2;
        if(pHead1->val <= pHead2->val)
        {
            pHead = pHead1;
            pHead->next = Merge(pHead1->next,pHead2);
        }
        else
        {
            pHead = pHead2;
            pHead->next = Merge(pHead1,pHead2->next);
        }
        return pHead;
    }
//方法二;
	class Solution {
public:
    
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead,*pre,*p;
        if(pHead2 == NULL )
            return pHead1;
        if(pHead1 == NULL )
            return pHead2;
        if(pHead1->val<=pHead2->val){
            pHead=pHead1;
            pHead1=pHead1->next;
        }
        else{
            pHead=pHead2;
            pHead2=pHead2->next;
        }  
        pre = pHead; //头结点需已知或初始化
        while(pHead1 != NULL && pHead2 !=NULL)
        {
            if(pHead1->val <= pHead2->val)
            {
                p = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p = pHead2;
                pHead2 = pHead2->next;
            }
            pre->next = p;
            pre = p;
        }
        if(pHead1 != NULL)
            pre->next = pHead1;
        else
            pre->next = pHead2;
        return pHead;
    }
};
//方法三：
class Solution {
public:
    
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead,*pre,*p,*p1;
        stack<ListNode*> s;
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        if(pHead1 == NULL && pHead2 != NULL)
            return pHead2;
        if(pHead1 == NULL && pHead1 != NULL)
            return pHead1;
        while(pHead1!= NULL && pHead2 != NULL)
        {
            if(pHead1->val >= pHead2->val)
               {
                s.push(pHead2);
                pHead2 = pHead2->next;
               }
            else
            {
                s.push(pHead1);
                pHead1 = pHead1->next;
            }
        }
       while(pHead2 != NULL)
        {
             s.push(pHead2);
             pHead2 = pHead2->next;
       }
       while(pHead1 != NULL)
        {
             s.push(pHead1);
             pHead1 = pHead1->next;
       }
        pre = NULL;
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            p->next = pre;
            pre = p;
            
        }
        pHead = p;
        return pHead;
    }
};