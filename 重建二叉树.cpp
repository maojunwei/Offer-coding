#include <iostream>
#include <iterator>
#include<string>
#include<stack>
#define Tmax 20
using namespace std;
typedef struct TreeNode {
      char data;
      TreeNode *left;
      TreeNode *right;
}*Ctree,bintree;
//按层遍历
void leveltree(Ctree treenode)
{
	int head,tail;
	Ctree q[Tmax];
	Ctree p;
	if(treenode == NULL)
		cout<<"树为空"<<endl;
	else
	{
		tail = 0;
		head = 1;
		q[head] = treenode;
		while(tail != head)



		{
			tail += 1;
			p = q[tail];
			cout<<p->data;
			if(p->left)
				q[++head] = p->left;
			if(p->right)
				q[++head] = p->right;		
		}
	}
}
//前序遍历（递归）
void preorder(Ctree treenode)
{
	if(treenode)
	{
		cout<<treenode->data;
		preorder(treenode->left);
		preorder(treenode->right);
	}
}
//前序（非递归）
void preorder1(Ctree treenode)
{
	std::stack<Ctree> s;
	Ctree p = treenode;
	while(p != NULL || !s.empty())
	{
		while(p!=NULL)
		{
			cout<<p->data;
			s.push(p);
			p = p->left;		
		}
		while(!s.empty())
		{
			p = s.top();
			s.pop();		
		    p = p->right;
		}
	}
}
//后序非递归
void reartree1(Ctree treenode)
{
	std::stack<Ctree> s;
	Ctree p = treenode;
	Ctree pre = NULL;
	s.push(treenode);
	while(!s.empty())
	{
		p = s.top();
		if((p->left!= NULL &&p->right!=NULL) ||(pre!=NULL &&(p->left == pre || p->right == pre)))
		{
			cout<<p->data;				
			s.pop();
			pre = p;		
		}
		else
		{
			if(p->right)
				s.push(p->right);
			if(p->left)
				s.push(p->left);
		}
	
	}
	
}
void qzh(string a,string b)
{
	int i;
	int ll,lr;
	for(i=0;i<a.length();i++)
		if(a[0] == b[i])
		{
			ll = i;
			lr = a.length() - ll -1;
			if(ll)
			{
				string part1(a,1,ll),part2(b,0,ll);
				qzh(part1,part2);
			}
			if(lr)
			{
				string part3(a,ll+1,lr),part4(b,ll+1,lr);
				qzh(part3,part4);
			}
			cout<<a[0];	
			break;
		}


}
Ctree cj(string a,string b)
{
	int ll,lr;
	Ctree treenode =  Ctree(malloc(sizeof(bintree)));
	treenode->left = NULL;
	treenode->right = NULL;
	treenode->data = a[0];
	for(int i=0;i<a.length();i++)
		if(a[0] == b[i])
		{
			ll = i;
			lr = a.length() - ll -1;
			if(ll)
			{
				string part1(a,1,ll),part2(b,0,ll);
				treenode->left = cj(part1,part2);
			}
			if(lr)
			{
				string part3(a,ll+1,lr),part4(b,ll+1,lr);
				treenode->right = cj(part3,part4);
			}
			break;
		}
	return treenode;
}
int main()
{
	string s1("12473568"); //前序
    string s2("47215386"); //中序
	//前中求后
	cout<<"后序为："<<endl;
	qzh(s1,s2);
	cout<<endl;
	//重建二叉树
	Ctree treenode1 = cj(s1,s2);
	preorder(treenode1);
	cout<<endl;
	leveltree(treenode1);
	system("pause");
	return 0;
	
}
