/*
题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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
        if(pHead == NULL || pHead->next == NULL) //零结点或只有一个结点
            return pHead;
        if(pHead->val == pHead->next->val) //当前结点为重复结点
        {
            ListNode* p = pHead->next;
            while(p!=NULL && p->val == pHead->val) //NUll->data无无意义，会报错
                p = p->next;
            return deleteDuplication(p); //从第一个非重复的结点开始递归
        }
        else
        {
            ListNode* p = pHead->next;
            pHead->next = deleteDuplication(p);  //保留当前结点，从下一个结点开始递归
            return pHead;
        }
    }
};