/*
��εõ�һ���������е���λ����������������ж�����������ֵ��
��ô��λ������������ֵ����֮��λ���м����ֵ�������������
�ж���ż������ֵ����ô��λ������������ֵ����֮���м�������
��ƽ��ֵ������ʹ��Insert()������ȡ��������ʹ��GetMedian()��
����ȡ��ǰ��ȡ���ݵ���λ����
*/
class Solution {
public:
    void Insert(int num)
    {
        v.push_back(num);
    }

    double GetMedian()
    { 
        int len = v.size();
       sort(v.begin(),v.end());
        if(len % 2 == 0)
            return double((v[len/2 -1] + v[len/2])/2.0 );
        else
            return double(v[len/2]);
    }
private: 
    vector<int> v;
};