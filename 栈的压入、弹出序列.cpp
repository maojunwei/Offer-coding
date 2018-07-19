/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳��
����4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int k = 0;
        for(int i=0;i<popV.size();i++)
        {
            while(s.empty() ||s.top() != popV[i])
            {
                s.push(pushV[k++]);
                if(k > popV.size() )
                    return false;
            }
            s.pop();
        }
        if(s.empty())
            return true;
        else
            return false;
    }
};