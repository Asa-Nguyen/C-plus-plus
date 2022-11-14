#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 
struct Student{
	string name, id;
	double gpa;
};
 
struct SV{
	Student s;
	SV *next;
};
 
typedef struct SV* sv;

//Khởi tạo danh sách mới
sv makeNode(){
	Student s;
	cout << "Nhap thong tin sinh vien : \n";
	cout << "Nhap ID : "; cin >> s.id;
	cout << "Nhap ten : "; cin.ignore();
	getline(cin, s.name);
	cout << "Nhap gpa : "; cin >> s.gpa;
	sv tmp = new SV();
	tmp->s = s;
	tmp->next = NULL;
	return tmp;
}

//Kiểm tra danh sách rỗng
bool isEmpty(sv a)
{
	return a == NULL;
}

int Size(sv a)
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
void insertFirst(sv &a)
{
	sv temp = makeNode();
	if(a==NULL)
	{   
		a = temp;
	}else{
		temp->next = a;
		a = temp;
	}
}

//Thêm phần tử cuối
void insertLast(sv &a)
{
	sv temp = makeNode();
	if(a==NULL){
		a = temp;
	}else{
		sv p = a;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
}

//Thêm phần tử giữa

void insertMiddle(sv &a,int pos)
{
	sv temp = makeNode();
	int n = Size(a);
	if(pos<=0 || pos > n+1){
		cout<<"Vi tri chen khong hop le \n";
	}
	if(n == 1)
	{
		insertFirst(a);
	}
	if(n == pos + 1){
		insertLast(a);
	}
	sv p = a;
	for(int i = 1; i<n;i++)
	{
		p = p->next;
	}
	temp -> next = p->next;
	p->next = temp;
}

void deleteFirst(sv &a)
{
	if(a==NULL)
		return;
	a = a->next;
}

void deleteLast(sv &a)
{
	if(a==NULL)
		{
			return;
		}
		sv truoc = NULL; 
		sv sau = a;
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

void deleteMiddle(sv &a,int pos)
{
	if(pos <= 0||pos>Size(a))
		return;
		sv truoc = NULL, sau = a;
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

void in(Student s){
	cout << "--------------------------------\n";
	cout << "ID : " << s.id << endl;
	cout << "Ho ten :" << s.name << endl;
	cout << "GPA : " << s.gpa << endl; 
	cout << "--------------------------------\n";
}



void inds(sv a){
	cout << "Danh sach sinh vien :\n";
	while(a != NULL){
		in(a->s);
		a = a->next;
	}
	cout << endl;
}

void in5(Student s){
	if(s.gpa>5){
		cout << "--------------------------------\n";
		cout << "ID : " << s.id << endl;
		cout << "Ho ten :" << s.name << endl;
		cout << "GPA : " << s.gpa << endl; 
		cout << "--------------------------------\n";
	}
	
}
void inds_GPA_5_higher(sv a){
	cout << "Danh sach sinh vien :\n";
	while(a != NULL){
		in5(a->s);
		a = a->next;
	}
	cout << endl;
}

void sortGPA(sv &a){
	for(sv p = a; p->next != NULL; p = p->next){
		sv min = p;
		for(sv q = p->next; q != NULL; q = q->next){
			if(q->s.gpa < min->s.gpa){
				min = q;
			}
		}
		Student tmp = min->s;
		min->s = p->s;
		p->s = tmp;
	}
}

void findName(sv a, char x[]){    
    int dem = 0;
    while (a!=NULL)
    {
        if(strcmp(x,a->s.name)==0)      dem++;
        a=a->next;
    }
    if(dem!=0)
    {
            printf("\nTim thay sv: "); in(a->s.name);
    }
    else printf("\nKo tim thay.");
}
//Hàm chính
int main()
{
	
	sv head = NULL;
	int x;
	while(true)
	{
		cout<<"1. Chen sinh vien vao dau danh sach\n";
		cout<<"2. Chen sinh vien vao cuoi danh sach\n";
		cout<<"3. Chen sinh vien vap giua danh sach\n";
		cout<<"4. Xoa sinh vien dau danh sach\n";
		cout<<"5. Xoa sinh vien cuoi danh sach\n";
		cout<<"6. Xoa sinh vien giua danh sach\n";
		cout<<"7. Xuat danh sach sinh vien\n";
		cout<<"8. Xuat danh sach sinh vien gpa > 5\n";
		cout<<"9. Tim sinh vien theo ten\n";
		cout<<"10. Sap xep danh sach sinh vien\n";
		int select;
		cin>>select;
		if(select == 1)
		{
			insertFirst(head);
		}
		else if(select == 2)
		{
			insertLast(head);
		}
		else if(select == 3)
		{
			int pos; cout << "Nhap vi tri can chen :"; cin >> pos;
			insertMiddle(head, pos);

		}
		else if(select == 4)
		{
			deleteFirst(head);
		}
		else if(select == 5)
		{
			deleteLast(head);
		}
		else if(select == 6)
		{
			int pos; cout << "Nhap vi tri can xoa:"; cin >> pos;
			deleteMiddle(head, pos);
		}
		else if(select==7)
		{
			inds(head);
		}
		else if(select==8)
		{
			inds_GPA_5_higher(head);
		}
		else if(select == 9)
		{
			char x[30];
			fflush(stdin);
    		gets(x);
			findName(head,x);
		}
		else if(select == 10)
		{
			sortGPA(head);
		}
	}
}