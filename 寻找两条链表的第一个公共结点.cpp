/*
输入两个链表，找出它们的第一个公共结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//方法一
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL; 
        vector<ListNode*> v1;
        vector<ListNode*> v2;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1!=NULL)
        {
            v1.push_back(p1);
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            v2.push_back(p2);
            p2 = p2->next;
        }
        int l1;
        bool flag = false;
        for(int i=0;i<v1.size() && (!flag);i++)
            for(int j=0;j<v2.size();j++)
            {
                if(v1[i] == v2[j])
                {   
                    flag = true;
                    l1 = i;
                    break;
                }
            }
        if(flag)
        {
            for(int i=0;i<l1;i++)
                pHead1 = pHead1->next;
            return pHead1;
        }
        return NULL;
        
    }
};