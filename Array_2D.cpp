#include<iostream>
using namespace std;
#define MAX 100
void NhapMang(int a[MAX][MAX], int dong, int cot)
{
	srand((int)time(0));
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){

			a[i][j] = rand() %50;
		}
	}
}

void XuatMang(int a[MAX][MAX],int dong,int cot)
{
	for(int i=0;i<dong;i++)
		{
			for(int j =0; j<cot;j++)
			{
				cout<<a[i][j]<<"\t";
			}cout<<endl;
		}
}

int TinhTongMaTran(int a[MAX][MAX],int dong, int cot)
{
	int s=0;
	for(int i =0 ; i<dong ; i++){
		for(int j=0;j<dong;j++)
		{
			s+=a[i][j];
		}
	}return s;
}

int TinhTrungBinhCongMaTran(int a[MAX][MAX],int dong, int cot)
{
	int s=0;
	float tb=0;
	for(int i =0 ; i<dong ; i++){
		for(int j=0;j<dong;j++)
		{
			s+=a[i][j];
		
		}
	}tb=s/(dong*cot);
	return (float)tb;
}

float TinhTrungBinhCongDuongMaTran(int a[MAX][MAX],int dong,int cot)
{
    int sum=0,dem=0;
    for (int i=0; i<dong; i++)
    {
    	for(int j=0;j<cot;j++){
    		if (a[i][j]>0)
        {
            sum+= a[i][j];
            dem++;
        }
		}
        
    }
    float tb=sum/dem;
    return tb;
}

void XuatPhanTuTrenDongK(int a[MAX][MAX],int dong, int cot, int k)
{


	for(int i=0;i<cot;i++){

			cout<<a[k][i]<<"\t";		
		
	}
}

int TongPhanTuTrenDongK(int a[MAX][MAX],int dong, int cot,int k)
{


	int s=0;
	for(int i=0;i<cot;i++){		
			s+=a[k][i];
	}return s;
}

int GiaTriLonNhat(int a[MAX][MAX], int dong, int cot){
	int max = a[0][0];
	for(int i=0;i<dong;i++)
	{
		for(int j =0 ; j<cot;j++){
			if(max<a[i][j])
			{
				max=a[i][j];
			}
		}
	}return max;
}


int main(){
	int dong;
	cout<<"Nhap so dong: ";
	cin>>dong;
	int cot;
	cout<<"Nhap so cot: ";
	cin>>cot;
	int a[100][100];
	NhapMang(a,dong,cot);
	XuatMang(a,dong,cot);
	//Tinh Tong Ma Tran
	int s;
	cout<<"Tong ma tran: "<<TinhTongMaTran(a,dong,cot)<<"\n";
	//Tinh trung binh cong ma tran
	float tb;
	cout<<"Trung binh cong ma tran: "<<TinhTrungBinhCongMaTran(a,dong,cot)<<"\n";
	//Tinh trung binh cong duong ma tran
	float tbd;
	cout<<"Trung binh cong ma tran duong: "<<TinhTrungBinhCongDuongMaTran(a,dong,cot)<<"\n";
	//Xuat phan tu dong K
	int k;
	cin>>k;
	cout<<"Cac phan tu dong thu "<<k<<": ";XuatPhanTuTrenDongK(a,dong,cot,k);cout<<"\n";
	//Ting Tong phan tu dong K
	cout<<"Tong phan tu dong "<<k<<": "<<TongPhanTuTrenDongK(a,dong,cot,k);
	//Tim gia tri lon nhat trong mang 2 chieu
	cout<<"Gia tri lon nhat trong mang 2 chieu: "<<GiaTriLonNhat(a,dong,cot);
	return 0;
}

