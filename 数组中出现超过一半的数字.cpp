/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������������0��
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0)
            return 0;
        const int num=10;
        int hash[num] = {0};
        for(int i=0;i<len;i++)
            hash[numbers[i]]++;
        for(int i =0;i<len;i++)
            if(hash[numbers[i]] > len/2)
                return numbers[i];
        return 0;
    
    }
};