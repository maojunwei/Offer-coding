#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
class Solution
{
public:
    void push(int node) {
          stack1.push(node);
        
    }

    int pop() {
        int top,t;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
         }
        top = stack2.top();
        stack2.pop();
        return top;
        
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};
class solution1
{
public:
	void stackpush(int node)
	{

		queue1.push(node);
	}
	int stackpop()
	{
		int l1,l2,top;
		l1 = queue1.size();
		for(int i=1;i<l1;i++)
		{
			queue2.push(queue1.front());
			queue1.pop();				   
		}
		top = queue1.front();
		queue1.pop();
		for(int i=1;i<l1;i++)
		{
			queue1.push(queue2.front());
			queue2.pop();	
		}
		return top;
	}
private:
	std::queue<int> queue1;
	std::queue<int> queue2;


};