#include<iostream>
using namespace std;
#include<malloc.h>
#include<conio.h>

void NhapSL(int *n)
{
	do{
		cin>>*n;
	}while(*n<0||*n>100);
}

void NhapMang(int *a, int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<"Nhap phan tu thu "<<i<<": ";
		cin>>*(a+i);
	}
}

void XuatMang(int *a, int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<*(a+i)<<"\t";
	}
}

int TongPhanTu(int *a, int n)
{
	int s = 0;
	for(int i = 0 ; i < n ; i++)
	{
		s+=*(a+i);
	}
	return s;
}

int main()
{
	int n;
	cout<<"Nhap so luong phan tu n: ";
	NhapSL(&n);
	int *a;
	a=new int[n];
	NhapMang(a,n);
	XuatMang(a,n);
	cout<<"\n";
	cout<<"Tong phan tu cua mang: "<<TongPhanTu(a,n);
	return 0;
}
