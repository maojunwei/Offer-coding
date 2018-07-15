#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct bintree
{
	struct bintree *right;
	struct bintree * left;
	struct bintree *parent;
	int data;
}Ctree;
Ctree* nextnode(Ctree* treenode)
{
	Ctree *p;
	if(treenode == NULL)
		return NULL;
	if(treenode->right !=NULL )  //右子树不为空
	{
		p = treenode->right;
		while(p->left != NULL)
			p = p->left;
		return p;	
	}
	else if(treenode->parent != NULL)//无右子树
	{
		if(treenode->parent->left == treenode)
			return treenode->parent;
		else
		{
			p = treenode;
			while(p->parent != p->parent->parent->left)
				p = p->parent;
			return p->parent->parent;		
		}

	}


}