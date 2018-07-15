#include<iostream>
#define l 50
using namespace std;
void replaceblank(char string[],int len)
{
	int numberb = 0;
	int length = 0,newlength;  //字符串实际长度
	if(string == NULL || len <= 0)
		return;
	for(int i=0;string[i];i++)
	 {
		 if(string[i] == ' ')
		     numberb++;
		 if(string[i]!= '\0')
			 length++;
	 }
	char *p1 = &string[length];   //char *p1;p1 = &string[length]; '\0'也要复制
	newlength = length+ 2 * numberb;
	if(newlength > len)
		return;
	char *p2 = &string[newlength];
	while(p1 != p2)
	{
	  if(*p1 != ' ')
	  {
		*p2 = *p1;
		p1--;
		p2--;
	  }
	  else
	  {
	    p1--;
		*(p2-2) = '%';
		*(p2-1) = '2';
		*p2 = '0';
		p2 = p2 - 3;
	  }	
	}
}
int main()
{
	char a[l] = {"We are happy"};
	//int len = sizeof(a)/sizeof(a[0]);
	puts(a);
	replaceblank(a,l);
	cout<<"替换空格后："<<endl;
	puts(a);
	system("pause"); 
	return 0;
}