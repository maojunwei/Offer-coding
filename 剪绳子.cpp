#include<iostream>
#include<math.h>
using namespace std;
//动态规划
int maxaftercutting(int length)
{
	int max = 0;
	int *p = new int[length + 1];
	if(length <= 1)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	for(int i =4;i<=length;i++)
	{
		
	    for(int j=1;j<=i/2;j++)  //自下而上
		{
			int p1 = p[i-j] * p[j];
			if (p1 >=max)
				max = p1;		
		}
	    p[i] = max;	
	}
	max = p[length];
	return max;
}
int maxaftercutting1(int length)
{
	int max =0;
	if(length <= 1)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;
	if(length == 4)
		return 4;
	int sizeof3 = length/3;
	
	if(length - sizeof3 * 3 == 1)
		sizeof3 -= 1;
	int sizeof2 = (length - sizeof3 * 3)/2;
	max = (int)(pow(float(3),float(sizeof3))) * (int)(pow(float(2),float(sizeof2))); //extern float pow(float x, float y)
	return max;
	
}
int main()
{
	int l;
	cout<<"请输入绳长："<<endl;
	cin>>l;
	cout<<"1;动态规划："<<maxaftercutting(l)<<endl;
	cout<<"2;贪心算法："<<maxaftercutting1(l)<<endl;
	system("pause");
	return 0;
}