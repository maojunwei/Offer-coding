#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
int strtoint(string s,int *num)
{
	int num1 =0;
	int m,n;
	int temp = 1; //ÅĞ¶ÏÕı¸ººÅ
	if(s.length() <=0)  //ÅĞ¶ÏÎª¿Õ
	{
		cout<<"×Ö·ûÎª¿Õ"<<endl;
		return 0;
	}
	if(s[0] == '-')
		temp = -1;
	for(int i =(s[0] == '+' || s[0] == '-')? 1:0;i<s.length();i++)
	{
		if(s[i] < '0' || s[i] > '9')  
		{
			cout<<"×Ö·û³¬³ö·¶Î§"<<endl;
			return 0;
		}
		else
		{
			n =  s[i] - '0';
			m = 10 * num1;
			num1 = m + n;
			if((n > 0 && m > 0 && num < 0) || (n < 0 && m < 0 && num > 0))  //ÅĞ¶ÏÒç³ö
			{
				cout<<"Òç³ö"<<endl;
				return 0;
			}
		}
	}
	*num = num1 * temp;
	return 1;
}
int main()
{
	char a[50];
	gets(a);
	string s(a);
	int num;
	if(strtoint(s,&num))
		cout<<num<<endl;
	system("pause");
	return 0;
	

}
