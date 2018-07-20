/*
题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中
最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。 
因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法再sort中调用
非静态成员函数。静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对
象实例就可以访问。同时静态成员函数不可以调用类的非静态成员。
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string s = "";
        if(len == 0)
            return s;
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<len;i++)
            s += to_string(numbers[i]);
        return s;
        }
       static bool cmp(int a,int b) //定义“小于”
        {
            string m = "";
            string n = "";
            m += to_string(a);
            m += to_string(b);
            n += to_string(b);
            n += to_string(a);
            return(m<n);
       }
};