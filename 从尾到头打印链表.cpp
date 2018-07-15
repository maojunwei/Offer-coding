#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef int elemtype;
typedef struct listnode  //����ڵ㶨��
{
  listnode *next;
  elemtype data;
}*link,lnode;
//���ַ�ʽʵ��
lnode* create(int n)  //����n���ڵ������ͷָ����ʽ
{
	link head,p,pre;
	int i;
	head = (link)malloc(sizeof(lnode));
	//head->next = NULL;
	pre = head;
	for(i =0;i<n;i++)
	{
	  p = (link)malloc(sizeof(lnode));
	  if(p == NULL)
	    break;
	  cout<<"����������ڵ�����"<<endl;
	  cin>>p->data;
	  pre->next = p;
	  pre = p;	
	}
	p->next = NULL;
	return head; 
}
link del(link head,int value)
{
  link p,delp;
  p = head;
  while(p->next != NULL && p->next->data != value)
	  p = p->next;
  if(p->next !=NULL && p->next->data == value)
    {
	  delp = p->next;
	  p->next = p->next->next;
	  free(delp);
	 }
   return head;
}

void addtotail(lnode **head,int value) //link *head ĩββ������һ���ڵ�,ͷ������
{
	link p = (lnode *)malloc(sizeof(lnode));
	p->next = NULL;
	p->data = value;
	lnode *pre = *head;
	if(*head == NULL)
		*head = p;
	else
	{
		while(pre->next != NULL)
			pre = pre->next;
		pre->next = p;  
	
	}
}
void removenode(lnode **head,int value)
{
	if(head == NULL && *head == NULL)
		return;
	lnode *delp;
	if((*head)->data == value)
	{
		delp = *head;
		*head = (*head)->next;
		free(delp);
	}
	else
	{
		lnode *p = *head;
		while(p->next != NULL && p->next->data != value)
			p = p->next;
		if(p->next != NULL && p->next->data == value)
		{
			delp = p->next;
			p->next = p->next->next;
			free(delp);
		}
	}
}
void print0(link head) //ͷָ����ʽ
{
	link p = head->next;
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
void print1(lnode *head)//ͷ�ڵ���ʽ
{
	lnode *p = head;
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}
//��β��ͷ��ӡ����

void fprint(link head) //ͷָ����ʽ head->next
{
	if(head != NULL)
	{
		if(head->next !=NULL)
			fprint(head->next);
		cout<<head->data<<endl;	
	}
}
void fprint1(lnode *head)  //ͷ�����ʽ
{
	lnode *p = head;
	if(head == NULL)
		return;
	if(p->next != NULL)
		fprint(p->next);
	cout<<p->data<<endl;
}
void fprint_stack(lnode *head)  //��ջʵ��
{
	std::stack<listnode *>nodes;
	listnode *p =head;
	while(p != NULL)
	{
	  nodes.push(p);
	  p = p->next;
	}
	while(!nodes.empty())
	{
		p = nodes.top();
		cout<<p->data<<endl;
		nodes.pop();	
	}
}
int main()
{
 link head;
 head = create(3);
 print0(head);
 fprint(head->next);
 print0(head);
 lnode *head1 = NULL;
 addtotail(&head1,6); //ָ��ָ���ָ��
 addtotail(&head1,9);
 addtotail(&head1,12);
 print1(head1);
 fprint1(head1);
 fprint_stack(head1);
 print1(head1);
 system("pause");
 return 0;
}