#include <iostream>
class solusion
{
public:
	void sortages(int ages[],int length)
	{
		if(ages == NULL||length<0)
			return;
		const int oldage = 99;  
		int agetimes[oldage+1];  //a[n],数组大小必须为常量
	    for(int i=0;i<=oldage;i++)
			agetimes[i] = 0;
		for(int i = 0;i<length;i++)
		{
			int age = ages[i];
			if(age>oldage || age<0)
				throw new std::exception("age out of range");
			++agetimes[age];
		}
        int index = 0;
		for(int i=0;i<=oldage;i++)
			for(int j=0;j<agetimes[i];j++)
			{
				ages[index] = i;
				index++;			
			}
	
	}


};