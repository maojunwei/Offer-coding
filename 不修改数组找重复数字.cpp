#include<iostream>
using namespace std;
int countrange(const int *a,int length,int start,int end)
{
	int count = 0;
	if(a == NULL )
		return 0;
	for(int i = 0;i<length;i++)
	{
	   if(a[i]>=start && a[i]<=end)
		count++;
	}
	return count;
}
int getduplication(const int *a,int length)
{
	int i,k;
	int start = 0;
	int end = length - 1;
	
        while(end >=  start)
	{
		int mid = (start + end)/2; //start + (end - start)>>1
		int count = countrange(a,length,start,mid);
		if(start == end)
		{
		  if(count > 1)
			  return start;
		  else
			  break;
		}
		if(count > mid - start + 1)
			end = mid;
		else
			start = mid + 1;
	 }
         return -1;
}
int main()
{
	int a[] = {2,3,1,0,2,5,3};
	int length = sizeof(a)/sizeof(a[0]);
	cout<<getduplication(a,length)<<endl;
	system("pause");
	return 0;
}
