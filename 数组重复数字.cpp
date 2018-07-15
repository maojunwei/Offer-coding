#include<iostream>
using namespace std;
//class Solution{
//public:
//	bool dulicate(int numbers[],int length,int *duplication)
//	{
//	}
//
//};
bool dulicate(int numbers[],int length,int *duplication)
{
	int i,m,temp;
	if(length<1 ||numbers == NULL)
		return false;
	for(i = 0;i<length;i++)
	{
	   if(numbers[i]<0||numbers[i]>length - 1)
		   {
			   duplication = NULL;
	           return false;
	       }
	}
	for(i = 0;i<length;i++)
	{
		//if(numbers[i] == i)
		//	continue;
		//else
		//	{
		//		m = numbers[i];
		//		if(numbers[m] == m)
		//		{
  //                  *duplication = m;
		//			return true;
		//		}
		//		else
		//		{
		//		  numbers[i] = numbers[m];
		//		  numbers[m] = m;
		//		}
		//     }	
		while(numbers[i]!=i)
		{
		   if(numbers[i] == numbers[numbers[i]])
		   {
			 *duplication = numbers[i];
		     return true;
		   }
		   temp = numbers[i];
		   numbers[i] = numbers[temp];
           numbers[temp] = temp;
		}
	}
	return false;
}
int main()
{
	int a[] = {2,3,1,0,2,5,3};
	int len = sizeof(a)/sizeof(a[0]);
	int duplication;
	cout<<dulicate(a,len,&duplication)<<endl;
	cout<<duplication<<endl;
	system("pause");
	return 0;
	
}