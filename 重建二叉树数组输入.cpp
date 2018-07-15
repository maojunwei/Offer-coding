#include<iostream>
#include<stdlib.h>
#define Tlen 20
using namespace std;
typedef struct bintree
{
	struct bintree *right;
	struct bintree *left;
	int data;
}Ctree;
Ctree* constructcore(int *prestart,int *preend,int* instart,int* inend);
Ctree* construct(int *preorder,int *inorder,int length)
{
	if(preorder == NULL || inorder == NULL || length <=0)
		return NULL;
	return constructcore(preorder,preorder+length-1,inorder,inorder+length-1);
}
Ctree* constructcore(int* prestart,int* preend,int* instart,int* inend)
{
	Ctree* treenode = (Ctree*)(malloc(sizeof(Ctree)));
	int ll,lr;
	treenode->left = NULL;
	treenode->right = NULL;
	treenode->data = prestart[0];
	int len = preend - prestart + 1;
	for(int i=0;i<len;i++)
		if(prestart[0] == instart[i])
		{
			ll = i;
			lr = len - i - 1;
			
			if(ll)
			{
				treenode->left = constructcore(prestart+1,prestart+ll,instart,instart+ll-1);
			}
			if(lr)
			{
				treenode->right = constructcore(prestart+ll+1,preend,instart+ll+1,inend);
			}
			break;	
		}
		return treenode;
}
//
void leveltree(Ctree* treenode)
{
	int tail = 0,head = 0;
	Ctree* q[Tlen];
	if(treenode)
	{
		head = 1;
		q[head] = treenode;
	}
	while(head != tail)
	{
		Ctree* p;
		p = q[++tail];
		cout<<p->data<<" ";
		if(p->left)
			q[++head] = p->left;
		if(p->right)
			q[++head] = p->right;	
	
	}
}
int main()
{
	int pre[] = {1,2,4,7,3,5,6,8};
	int in[] = {4,7,2,1,5,3,8,6};
	int len = sizeof(pre)/sizeof(pre[0]);
	Ctree* tree = construct(pre,in,len);   
	leveltree(tree);
	system("pause");
	return 0;
}