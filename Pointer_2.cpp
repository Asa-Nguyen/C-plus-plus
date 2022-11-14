#include<iostream>
using namespace std;
struct PhanSo {
	int tu;
	int mau;
} typedef PS;

void NhapMotPhanSo(PS &ps) {

	do {
		cout<<"Nhap tu so: ";
		cin>>ps.tu;
		cout<<"Nhap mau so: ";
		cin>>ps.mau;
		if(ps.mau==0) {
			cout<<"Sai roi nhap lai"<<"\n";
		}
	} while(ps.mau==0);

}
void XuatMotPhanSo(PS &ps) {
	cout<<ps.tu<<"/"<<ps.mau;
}
void NhapMang(PS *a, int n) {
	for(int i = 0 ; i<n; i++) {
		NhapMotPhanSo(a[i]);
	}
}
void XuatMang(PS *a, int n) {
	for(int i = 0 ; i<n; i++) {
		XuatMotPhanSo(a[i]);
		cout<<"\t";
	}
}

int main() {
	int n;
	cin>>n;
	PS *a;
	a = new PS[n];
	int tu,mau;
	NhapMang(a,n);
	XuatMang(a,n);
	cout<<PhanSoLonNhat(a,n);
}
