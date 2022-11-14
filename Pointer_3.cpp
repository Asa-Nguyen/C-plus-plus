#include<iostream>
using namespace std;
#include<malloc.h>
#include<conio.h>



void NhapMang(int **a, int d,int c)
{
	for(int i = 0 ; i < d ; i++)
	{
		for(int j = 0 ; j < c; j++ )
		{
			cout<<"Nhap phan tu dong "<<i<<" cot "<<j<<" : ";
			cin>>*(*(a+i)+j);
		}
	}
}

void XuatMang(int **a, int d,int c)
{
	for(int i = 0 ; i < d ; i++)
	{
		for(int j = 0 ; j<c;j++){
			cout<<*(*(a+i)+j)<<"\t";
		}
		cout<<"\n";
		
	}
}

int TongMang(int **a, int d,int c)
{
	int s = 0;
	for(int i = 0 ; i < d ; i++)
	{
		for(int j = 0 ; j<c;j++){
			s+=*(*(a+i)+j);
		}
		
		
	}return s;
}

int main()
{
	int d,c;
	cout<<"Nhap so dong: ";
		cin>>d;
		cout<<"Nhap so cot: ";
		cin>>c;

	int **a;
	a=new int*[d];
	for(int i = 0 ;i<d;++i)
	{
		a[i] = new int[c];
	}
	NhapMang(a,d,c);
	XuatMang(a,d,c);
	cout<<"Tong phan tu: "<<TongMang(a,d,c);
	return 0;
}
