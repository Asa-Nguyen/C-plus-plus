#include<iostream>
using namespace std;

//Khai báo danh sách liên kết đơn
struct Node
{
	int data;
	Node* next;
};

typedef struct Node* node;

//Khởi tạo danh sách mới
node makeNode(int x)
{
	node temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

//Kiểm tra danh sách rỗng
bool isEmpty(node a)
{
	return a == NULL;
}

int Size(node a)
{
	int dem = 0;
	while(a!=NULL)
	{
		++dem;
		a = a->next; // gán địa chỉ next tiếp theo cho node hiện tại
		//node hiện tại sang node tiếp theo
	}
	return dem;
}

//Thêm 1 phần tử vào đầu danh sách liên kết
void insertFirst(node &a,int x)
{
	node temp = makeNode(x);
	if(a==NULL)
	{   
		a = temp;
	}else{
		temp->next = a;
		a = temp;
	}
}

//Thêm phần tử cuối
void insertLast(node &a,int x)
{
	node temp = makeNode(x);
	if(a==NULL){
		a = temp;
	}else{
		node p = a;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}

//Thêm phần tử giữa

void insertMiddle(node &a,int x,int pos)
{
	node temp = makeNode(x);
	int n = Size(a);
	if(pos<=0 || pos > n+1){
		cout<<"Vi tri chen khong hop le \n";
	}
	if(n == 1)
	{
		insertFirst(a,x);
	}
	if(n == pos + 1){
		insertLast(a,x);
	}
	node p = a;
	for(int i = 1; i<n;i++)
	{
		p = p->next;
	}
	temp -> next = p->next;
	p->next = temp;
}

void deleteFirst(node &a)
{
	if(a==NULL)
		return;
	a = a->next;
}

void deleteLast(node &a)
{
	if(a==NULL)
		{
			return;
		}
		node truoc = NULL; 
		node sau = a;
		while(sau->next != NULL)
		{
			truoc = sau;
			sau = sau->next;
		}
		if(truoc == NULL){
			a = NULL;
		}else
		{
			truoc->next = NULL;
		}
}

void deleteMiddle(node &a,int x,int pos)
{
	if(pos <= 0||pos>Size(a))
		return;
		node truoc = NULL, sau = a;
		for(int i=0;i<pos;i++)
		{
			truoc = sau;
			sau = sau ->next;
		}
		if(truoc==NULL)
		{
			a = a->next;
		}
		else
		{
			truoc->next = sau->next;	
		}
}

void printList(node a)
{
	cout<<"-----------------------------------------------------------------------------------\n";
	while(a!=NULL)
	{
		cout<< a->data <<" ";
		a = a->next;
	}
	cout<<"------------------------------------------------------------------------------------\n";
	
}

void Input(int &x)
{
	cout<<"Nhap gia tri can chen: ";
	cin>>x;
}

//Hàm chính
int main()
{
	node head = NULL;
	int x;
	while(true)
	{
		cout<<"1. Chen phan tu vao dau danh sach\n";
		cout<<"2. Chen phan tu vao cuoi danh sach\n";
		cout<<"3. Chen phan tu vap giua danh sach\n";
		cout<<"4. Xoa phan tu dau danh sach\n";
		cout<<"5. Xoa phan tu cuoi danh sach\n";
		cout<<"6. Xoa phan tu giua danh sach\n";
		cout<<"7. Xuat danh sach lien ket don\n";
		int select;
		cin>>select;
		if(select == 1)
		{
			Input(x);
			insertFirst(head,x);
		}
		if(select == 2)
		{
			Input(x);
			insertLast(head,x);
		}
		if(select == 3)
		{
			Input(x);
			int pos;
			cin>>pos;
			insertMiddle(head,x,pos);

		}
		if(select == 4)
		{
			Input(x);
			deleteFirst(head);
		}
		if(select == 5)
		{
			Input(x);
			deleteLast(head);
		}
		if(select == 6)
		{
			Input(x);
			int pos;
			cin>>pos;
			deleteMiddle(head,x,pos);
		}
		if(select==7)
		{
			printList(head);
		}
	}
}