#include<iostream>
using namespace std;
//class solution{
//public:
//	bo
//
//};
bool searchmatrix(int *datas,int rows,int columns,int number)
{
	bool found = false;
	int right_jiao;
	if (datas != NULL && rows > 0 && columns >0)
	{
		int row = 0;
		int col = columns - 1;
		while(row < rows && col >0)
		{
		  right_jiao = datas[row * columns + col];  //
		  if(right_jiao == number)
		  {
			found = true;
			break;
		  }
		  else if(right_jiao > number)
			  col--;
		  else 
			  row++;		
		}
	}
    return found;
}
int main()
{
	int a[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13}};
	int *p= &a[0][0];
	//int *p = NULL;
	int row = sizeof(a)/sizeof(a[0]);
	int col = sizeof(a[0])/sizeof(a[0][0]);
	int number = 10;   //���ҵ�����
	if(searchmatrix(p,row,col,number))
		cout<<number<<"����"<<endl;
	else
		cout<<number<<"������"<<endl;
	system("pause");
	return 0;
}