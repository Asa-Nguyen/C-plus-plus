#include<iostream>
using namespace std;
#define MAX 100 
#include<time.h>
#include<stdlib.h>
void NhapMang(int a[MAX][MAX], int dong, int cot)
{
	srand((int)time(0));
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){

			a[i][j] = rand() %50;
		}
	}
}

void XuatMang(int a[MAX][MAX], int dong, int cot)
{
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			cout<<a[i][j]<<"\t";
		}cout<<"\n";
	}	
}

void DuongCheoChinh(int a[MAX][MAX], int dong, int cot){
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			if(i==j)
			{
				cout<<a[i][j]<<"\t";
			}else{
				cout<<"\t";
			}
			
		}cout<<"\n";
	}
}

void DuongCheoPhu(int a[MAX][MAX], int dong, int cot){
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			if(dong==cot){
				if(i+j==dong-1){
					cout<<a[i][j]<<"\t";
				}
			}
		}
	}
}

int TongPhanTuDongK(int a[MAX][MAX], int dong, int cot,int k){
	int s=0;
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			if(i==k){
				s+=a[k][j];
			}
				
			
		}
	}return s;
}

void TongPhanTuMoiDong(int a[MAX][MAX], int dong, int cot){
	
	for(int i=0;i<dong;i++){
		int s=0;
		for(int j=0;j<cot;j++){
			s+=a[i][j];
		}cout<<"Tong dong thu"<<i<<": "<<s<<"\n";
	}
}

int TongPhanTuDongLonNhat(int a[MAX][MAX], int dong, int cot){
	int Max=a[0][0];
	int vt_max;
	for(int i=0;i<dong;i++){
		int s=0;
		for(int j=0;j<cot;j++){
			s+=a[i][j];
			if(Max<s){
				Max=s;
				vt_max=i;
			}
		}
		
		
	}cout<<"Tong lon nhat"<<": "<<Max<<"\n";
}

int main(){
	int dong,cot;
	cout<<"Nhap so luong dong: ";
	cin>>dong;
	cout<<"Nhap so luong cot: ";
	cin>>cot;
	int a[MAX][MAX];
	NhapMang(a,dong,cot);
	XuatMang(a,dong,cot);
	cout<<"\n";
	cout<<"duong cheo chinh"<<"\n";
	DuongCheoChinh(a,dong,cot);
	cout<<"duong cheo phu"<<"\n";
	DuongCheoPhu(a,dong,cot);
	int k;
	cout<<"Nhap k: ";
	cin>>k;
	cout<<"Tong phan tu duong thu"<<k<<": "<<TongPhanTuDongK(a,dong,cot,k)<<endl;
	TongPhanTuMoiDong(a,dong,cot);
	TongPhanTuDongLonNhat(a,dong,cot);
	return 0;
}
