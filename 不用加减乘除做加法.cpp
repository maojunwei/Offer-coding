//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
/*��λֵΪ������ѭ��*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        if(num1 == 0)
            return num2;
        while(num2 != 0)
        {
            int temp = num1^num2;//ȡ��򣬸�λ��Ӳ�������λ��ֵ
            num2 = (num1 & num2)<<1;//ȡ������һλ����λ
            num1 = temp;
        }
        return num1;
    }
};