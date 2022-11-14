#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h>

void NhapChuoi(char *s1,char *s2)
{
	
	fflush(stdin);
	gets(s1);
	fflush(stdin);
	gets(s2);
	
}

void XuatChuoi(char *s1, char *s2)
{
	cout<<"Chuoi 1: "<<s1<<"\n";
	cout<<"Chuoi 2: "<<s2<<"\n";
}

void SoSanhChuoi(char *s1, char *s2)
{
	if(strcmp(s1,s2)==0)
	{
		cout<<"Chuoi 1 bang chuoi 2";
	}
	else if(strcmp(s1,s2)>0)
	{
		cout<<"Chuoi 1 co ky tu lon hon chuoi 2";
	}
	else if(strcmp(s1,s2)<0)
	{
		cout<<"Chuoi 2 co ky tu lon hon chuoi 1";
	}
}

void NoiChuoi(char *s1, char *s2)
{
	strcat(s1,s2);
}

void KtrChuoi1(char *s1,char *s2)
{

		if(strstr(s1,s2)==NULL)
		{
			cout<<"Chuoi 1 khong chua chuoi 2";
		}else{
				cout<<"Chuoi 1 chua chuoi 2";
		}
	
}
int main(){
	char *s1;
	char *s2;
	s1 = new char[100];	
	s2 = new char[100];
	NhapChuoi(s1,s2);
	XuatChuoi(s1,s2);
	cout<<"\n";
	SoSanhChuoi(s1,s2);
	cout<<"\n";
	 NoiChuoi(s1,s2);
	 cout<<"\n";
	KtrChuoi1(s1,s2);
	return 0;
}
