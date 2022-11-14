#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
typedef struct Node* node;
typedef node tree;

void KhoiTaoCay(tree &t)
{
	t = NULL;
}

void Duyet_NLR(tree t)
{
	if(t!=NULL)
	{
		cout<<t->data<<" ";
		Duyet_NLR(t->left);
		Duyet_NLR(t->right);
	}
}

void Duyet_LNR(tree t)
{
	if(t!=NULL)
	{
		Duyet_NLR(t->left);
		cout<<t->data<<" ";
		Duyet_NLR(t->right);
	}
}

void Duyet_LRN(tree t)
{
	if(t!=NULL)
	{
		Duyet_NLR(t->left);
		Duyet_NLR(t->right);
		cout<<t->data<<" ";
	}
}



int Dem_La(tree t)
{   if(t==NULL) 
		return 0;
    else 	
	   	return 1 + Dem_La(t->left)+Dem_La(t->right);
}

void insert_node_into_tree(tree &t , int x){
	if(t==NULL)
	{
		node p = new Node;
		p->data = x;
		p->left=NULL;
		p->right=NULL;
		t=p;
	}
	else{
		if(t->data > x)
		{
			insert_node_into_tree(t->left,x);
		}
		else if(t->data < x)
		{
			insert_node_into_tree(t->right,x);
		}
	}
	
}

bool isLeafNode(tree t){
	return (t->left == NULL && t->right == NULL);
}
int countLeafNode(tree t){
	if (t == NULL) return 0;
	if (isLeafNode(t)) return 1;
	return countLeafNode(t->left) + countLeafNode(t->right);
}

void Menu(tree &t)
{
	while(true)
	{
		
		cout<<"\n\n\t\t =========== MENU ==========";
		cout<<"\n1.Nhap du lieu: ";
		cout<<"\n2. Xuat so node trong cay: ";
		cout<<"\n3. Xuat so node trong la: ";
		cout<<"\n4. Xuat node theo NLR: ";
		cout<<"\n5. Xuat node theo LNR: ";
		cout<<"\n6. Xuat node theo LRN: ";
		cout<<"\n\n\t\t ===========================";
		int lua_chon;
		cout<<"\nNhap lua chon";
		cin>>lua_chon;
		if(lua_chon<0||lua_chon>6)
		{
			cout<<"Lua chon khong hop le";
			system("pause");
		}else if(lua_chon==1)
		{
			int n;
			cout<<"\nNhap kich thuoc mang: ";
			cin>>n;
			int a[n];
			for(int i = 0 ; i<n;i++)
			{
				cout<<"\nNhap phan tu a["<<i<<"]: ";
				cin>>a[i];
			}
			for(int i =0;i<n;i++)
			{
				insert_node_into_tree(t,a[i]);
			}
		}
		else if(lua_chon==2)
		{
			cout<<"\n\n\t\t kich thuoc node cua cay:\n";
			cout<<Dem_La(t);	
		}
			else if(lua_chon==3)
		{
			cout<<"\n\n\t\t Dem node cua la:\n";
			cout<<countLeafNode(t);	
		}
		else if(lua_chon==4)
		{
			cout<<"\n\n\t\t cac node trong La:\n";
			Duyet_NLR(t);	
		}
		else if(lua_chon==5)
		{
			cout<<"\n\n\t\t cac node trong La LNR: \n";
			Duyet_LNR(t);	
		}
		else if(lua_chon==6)
		{
			cout<<"\n\n\t\t cac node trong La LRN: \n";
			Duyet_LRN(t);	
		}
		else{
			break;
		}
	}
}


int main()
{
	tree t;
	KhoiTaoCay(t);
	Menu(t);
	system("pause");
	return 0;
}