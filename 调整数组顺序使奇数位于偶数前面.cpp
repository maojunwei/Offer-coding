//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int temp;
        for(int i = 0;i<array.size();i++)
        for(int j =array.size()-1;j>i;j--)
        {
            if(array[j] % 2 == 1 &&array[j-1] % 2 == 0)
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
};