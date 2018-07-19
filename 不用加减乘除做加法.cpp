//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
/*进位值为零跳出循环*/
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
            int temp = num1^num2;//取异或，各位相加不包括进位的值
            num2 = (num1 & num2)<<1;//取与左移一位，进位
            num1 = temp;
        }
        return num1;
    }
};