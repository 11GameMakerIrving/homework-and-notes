#include<iostream>
using namespace std;



//����������������
struct Node
{
	int coe;
	int index;
	Node* next;
};
typedef Node* NodePtr;


//��������
void attatch(int a, int b, NodePtr* ptr);
NodePtr input();
void output(NodePtr p);
NodePtr Add(NodePtr p1, NodePtr p2);
NodePtr Multiple(NodePtr p1, NodePtr p2);








int main()
{
	NodePtr p1=input(),p2=input();
	NodePtr pmal = Multiple(p1, p2);
	NodePtr padd = Add(p1, p2);
	
	output(pmal);
	output(padd);
	return 0;
}



//��Ӷ���ʽ
void attatch(int a, int b, NodePtr* ptr)
{
	NodePtr x= (NodePtr)malloc(sizeof(Node));
	x->coe = a;
	x->index = b;
	x->next = NULL;
	(*ptr)->next = x;
	(*ptr) = x;
}




//�������ʽ
NodePtr input()
{
	NodePtr p = NULL;
	//����սڵ��p���г�ʼ��
	NodePtr ptr = (NodePtr)malloc(sizeof(Node)); 
	ptr->next = NULL;
	p = ptr;

	int n;
	cin >> n;

	for (; n > 0; n--)
	{
		int a;  //����ϵ����ָ��
		cin >> a;  
		int b;
		cin >> b;

		attatch(a, b, &ptr);
	}

	//ɾ���սڵ�
	NodePtr t = p;
	p = p->next;
	free(t);

	return p;
}


//�������ʽ
void output(NodePtr p)
{
	int flag = 0;

	if (p== NULL)
	{
		cout << "0 0" << endl;
		return;
	}

	for (NodePtr ptr = p; ptr!= NULL; ptr = ptr->next)
	{
		if (flag == 0)
		{
			cout << ptr->coe << " " << ptr->index;
		}
		else
		{
			cout << " " << ptr->coe << " " << ptr->index;
		}
		flag++;
	}
	cout << endl;
}


//�ӷ�
NodePtr Add(NodePtr p1, NodePtr p2)
{
	NodePtr p = (NodePtr)malloc(sizeof(Node)); //���սڵ��ʱ���Ҫ�뵽���ɾ���սڵ�
	p->next = NULL;
	NodePtr ptr = p;

	//�����
	while (p1 && p2)
	{
		if (p1->index > p2->index)
		{
			attatch(p1->coe, p1->index, &ptr);
			p1 = p1->next;
		}
		else if(p1->index<p2->index)
		{
			attatch(p2->coe, p2->index, &ptr);
			p2 = p2->next;
		}
		else
		{
			int sum = p1->coe + p2->coe;
			if (sum != 0)
			{
				attatch(sum, p1->index, &ptr);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1)
	{
		attatch(p1->coe, p1->index, &ptr);
		p1 = p1->next;
	}
	while (p2)
	{
		attatch(p2->coe, p2->index, &ptr);
		p2 = p2->next;
	}
	//ɾ���սڵ�
	NodePtr t = p;
	p = p->next;
	free(t);

	return p;
}


//�˷�
NodePtr Multiple(NodePtr p1, NodePtr p2)
{
	NodePtr p = (NodePtr)malloc(sizeof(Node)); //���սڵ��ʱ���Ҫ�뵽���ɾ���սڵ�
	p->next = NULL;
	NodePtr ptr = p,ptr1=p1,ptr2=p2;

	if (p1 == NULL||p2==NULL)
	{
		
		return NULL;
	}

	for (ptr1=p1; ptr1 != NULL; ptr1 = ptr1->next)
	{
		for (ptr2=p2; ptr2 != NULL; ptr2 = ptr2->next)
		{ //����
			NodePtr x = (NodePtr)malloc(sizeof(Node));
			x->coe = ptr1->coe* ptr2->coe;
			x->index = ptr1->index+ ptr2->index;
			x->next = NULL;
			for (ptr=p;; ptr = ptr->next)
			{
				if (ptr->next == NULL)
				{
					ptr->next = x;
					break;
				}
				else if (x->index > ptr->next->index&&ptr==p)
				{
					x->next = p->next;
					p->next= x;
					break;
				}
				else if(x->index < ptr->next->index && ptr->next->next==NULL)
				{
					ptr->next->next = x;
					break;
				}
				else if (x->index < ptr->next->index && x->index>ptr->next->next->index)
				{
					x->next = ptr->next->next;
					ptr->next->next = x;
					break;
				}
				else if (x->index == ptr->next->index)
				{
					int sum = x->coe + ptr->next->coe;
					if (sum != 0)
					{
						ptr->next->coe = sum;
					}
					else
					{
						ptr->next = ptr->next->next;
					}
					break;
				}
			}
			
		}
	}
	//ɾ���սڵ�
	NodePtr t = p;
	p = p->next;
	free(t);
	return p;
}