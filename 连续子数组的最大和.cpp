/*
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();
        if(len == 0)
            return 0;
        int max = array[0];
        int sum=0;
        for(int i = 0;i<len;i++)
            for(int j = i;j<len;j++)
            {
                sum = getsum(array,i,j);
                if(sum>max)
                    max = sum;                    
            }
        return max;
    }
    int getsum(vector<int> n,int i, int j)
    {
        int s = 0;
        for(int k = i;k<=j;k++)
            s += n[k];
        return s;
    }
};