#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAX 100
struct DATE
{
	int day;
	int month;
	int year;
}typedef date;

struct INFORMATION
{
	char id[11];
	char name[31];
	date Date;
	char gender;
	char Class[8];
	float grade;
}typedef IN4;

//
void Input_DATE(date &d);
void Ouput_DATE(date &d);
void Input_1_Student(IN4 &x);
void Amount_Student(int &n);
void Output_1_Student(IN4 &x);
void Input_List_Student(IN4 a[], int n);
void Output_List_Student(IN4 a[], int n);
//

void Input_DATE(date &d)
{
	cout<<("Please input day: ");
	cin>>d.day;
	cout<<("Please input month: ");
	cin>>d.month;
	cout<<("Please input year: ");
	cin>>d.year;
}

void Ouput_DATE(date &d)
{
	cout<<"-Day "<<d.day<<"/"<<"Month "<<d.month<<"/"<<"Year "<<d.year;
}

void Input_1_Student(IN4 &x)
{
	cout<<"\n"<<"Please Input id: "<<"\n";
	cin>>x.id;
	cout<<"Input Name: ";
	fflush(stdin);
	gets(x.name);
	cout<<"Input Birth ";
	Input_DATE(x.Date);
	do{
		cout<<"Choose gender x-Female y-Male: ";
		x.gender = getche();
	}while(x.gender!='x'&&x.gender!='y');
	cout<<"\n"<<"Input Class: ";
	cin>>x.Class;
	cout<<"\n"<<("Input grade: ")<<"\n";
	cin>>x.grade;
}

void Output_1_Student(IN4 &x){
	cout<<"\t"<<x.id<<"-"<<x.name;
	if(x.gender=='x'){
		cout<<"-"<<"Female";
	}else{
		cout<<"-"<<"Male";
	}
	Ouput_DATE(x.Date);
	cout<<"-"<<"Class: "<<x.Class;
	cout<<"-"<<"Grade: "<<x.grade;
	
} 

void Amount_Student(int &n)
{
	do{
		cout<<"Input amount student: ";
		cin>>n;
	}while(n<=0);
}

void Input_List_Student(IN4 a[], int n){
	cout<<"\n------INPUT LIST STUDENT------"<<"\n";
	for(int i = 0 ; i < n ; i++){
		cout<<"\n"<<"Input information of student "<<i<<": ";
		Input_1_Student(a[i]);
	}
}

void Output_List_Student(IN4 a[], int n){
	cout<<"\n------LIST STUDENT------"<<"\n";
	for(int i = 0 ; i < n ; i++){
		cout<<"Information of student "<<i<<": ";
		Output_1_Student(a[i]);
		cout<<"\n";
	}
}

int FindId(IN4 a[], int n, char fid[] )
{
	for(int i = 0; i<n ;i++){
		if(strcmp(a[i].id,fid)==0){
			return i;
		}
	}return -1;
}

void Grade_Higher_5(IN4 a[], int n)
{
	for(int i = 0; i<n ;i++){
		if(a[i].grade>5){
			Output_1_Student(a[i]);
		}
	}
}

void Find_amount_Female(IN4 a[], int n)
{
	int count = 0;
	for(int i = 0 ; i<n ; i++){
			if(a[i].gender=='x'){
				count++;
			}
	}cout<<"There have "<<count<<" Female";
}

void Output_Students_Have_Highest_Grade(IN4 a[], int n){
	int max = a[0].grade;
	for(int i = 0 ; i<n;i++){
		if(max<a[i].grade){
			max=a[i].grade;
		}
	}
	for(int i = 0 ; i<n;i++){
		if(max==a[i].grade){
			cout<<"List Student have highest grade: "
			Output_1_Student(a[i]);
		}
	}
	
}

int main()
{
	IN4 a[MAX];
	int n;
	Amount_Student(n);
	Input_List_Student(a,n);
	Output_List_Student(a,n);
	char fid[11];
	cout<<"Input id need to find: ";
	cin>>fid;
	int pos = FindId(a,n,fid);
	
	if(FindId(a,n,fid)==-1){
		cout<<"Can't find result ";
	}else{
		Output_1_Student(a[pos]);
	}
	cout<<"List student have grade higher 5:"<<"\n";
	 Grade_Higher_5(a,n);
	 cout<<"\n";
	Find_amount_Female(a,n);
	Output_Students_Have_Highest_Grade(a,n);
	return 0;
}
