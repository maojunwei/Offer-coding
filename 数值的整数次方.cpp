//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution {
public:
    double Power(double base, int exponent) {
        double s1 = 1.0,s2 = base;
        bool a = true;
        if(exponent == 0)
            return s1;
        if(exponent<0)
        {
            a = false;
            exponent *= -1;
        }
            
        for(int i =1;i <= exponent;i++)
        {
            s1 = s1 * s2;           
            
        }
        if(a)
            return s1;
        else
            return (1.0/s1);
    
    }
};