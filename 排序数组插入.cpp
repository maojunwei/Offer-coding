#include<iostream>
using namespace std;
void sortinsert(int *a,int *b,int la,int lb)  //¹é²¢Ë¼Ïë
{
	if(a == NULL || b == NULL )
		return;
	int *p1 = &a[la-1];
	int *p2 = &b[lb-1];
	int *p3;
	p3 = p1 + lb;
	while(p1 >= &a[0] && p2 >= &b[0])
	{
	  if(*p1 >= *p2 )
	  { 
		*p3 = *p1;
		p1--;
		p3--;		
	  }
	  else
	  {
		*p3 = *p2;
		p3--;
		p2--;
	  }	
	}
	while(p1 >= &a[0] )
	{
	    *p3 = *p1;
		p1--;
		p3--;

	}
	while(p2 >= &b[0])
	{
		*p3 = *p2;
		p3--;
		p2--;
	}
}
int main()
{
	int a1[] = {0,0,2,4,6,8,16};
	int a2[] ={1,2,3,4};
	int len_a1 = sizeof(a1)/sizeof(a1[0]);
	int len_a2 = sizeof(a2)/sizeof(a2[0]);
	sortinsert(a1,a2,len_a1,len_a2);
	for(int i=0;i<=len_a1+len_a2 - 1;i++)
		cout<<a1[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}