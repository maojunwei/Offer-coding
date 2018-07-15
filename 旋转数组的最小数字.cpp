#include<iostream>
using namespace std;
int xzsmall(int a[],int length)
{
	int *start = &a[0];
	int *end = &a[length - 1];
	if(*start<= *end)
		return *start;
	else
	{
	   while(end != start+1)
	   {
		   if(*(start+1)>=a[0])
			   start++;
		   if(*(end-1)<=a[length - 1])
			   end--;   
	   
	   }
	   return *end;
	
	}
}
//int xzsmall2(int a[],int length)
//{
//	int index1,index2;
//	index1 = 0;
//	index2 = length - 1;
//	if(a == null || length<0)
//		throw std::exception("wrong input");
//	if(a[index1]<a[index2])
//		return a[index1];
//	while(index2 != index1+1 )
//	{
//		int mid = (index1 + index2)/2;
//		if(a[mid]>=a[index1])
//		index1 = mid;
//		if(a[mid]<=a[index2])
//			index2 = mid;	
//	}
//	return a[index2];
//}
int mininorder(int a[],int index1,int index2) //遍历
{
	int m = a[index1];
	for(int i=index1+1;i<index2;i++)
	{
	  if(m > a[i])
		  m = a[i];
	}
	return m;
}
int xzsmall2(int a[],int length)
{
	int index1 =0,index2 = length-1;
	int mid = index1;
	while(a[index1] >= a[index2])
	{
		if(index2 = index1 +1)
		{
			mid = index2;
			break;
		}
		mid = (index1 + index2)/2;
		if(a[index1] == a[index2] && a[index1] == a[mid])
			return mininorder(a,index1,index2);
		if(a[mid] >= a[index1])
			index1 = mid;
		if  (a[mid] <= a[index2])
			index2 = mid;	
		
	}
	return a[mid];
}
int main()
{
	int n[] = {1,0,1,1,1};  //1,0,1,1,1
	int len = sizeof(n)/sizeof(n[0]);
	int num = xzsmall2(n,len);
	cout<<"旋转数组最小元素："<<num<<endl;
	system("pause");
    return 0;
    
}
