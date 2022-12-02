#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 150
#define inputfile "C:/test.txt"
#include<conio.h>
#include<stdlib.h>
#define VOCUC 1000
int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];

typedef struct GRAPH {
	int n; // so dinh cua do thi
	int a[MAX][MAX]; // ma tran ke cua do thi
}DOTHI;

//int DocMaTranKe(char TenFile[100],DOTHI &g)
//{
//	FILE *f;
//	f = fopen(TenFile,"rt");
//	if(f==NULL){
//		cout<<"Khong mo duoc file\n";
//		return 0;
//	}
//	fscanf(f,"%d",&g.n);
//	for(int i=0;i<g.n;i++){
//		for(int j = 0 ; j < g.n ; j++){
//			fscanf(f,"%d",&g.a[i][j]);
//		}
//	}fclose(f);
//	return 1;
//}

void XuatMaTranKe(DOTHI g){
	cout<<"So dinh cua do thi la: "<<g.n<<"\n";
	cout<<"Ma tran ke cua do thi la: \n";
	for(int i = 0 ; i <g.n;i++)
	{
		for(int j = 0 ; j<g.n;j++){
			cout<<g.a[i][j]<<"\t";
		}cout<<"\n";
	}
}

int TimDuongDiNhoNhat(DOTHI g){
	int li = -1; // Neu khong tim thay dinh nao thoa dieu kien thi tra ve -1
	float p = VOCUC;
	for(int i = 0 ; i < g.n ; i++){
		if(ChuaXet[i] == 0 && DoDaiDuongDiToi[i]<p){
			p = DoDaiDuongDiToi[i];
			li = i;
		}		
	}
	return li;
}


void CapNhatDuongDi(int u,DOTHI g){
	ChuaXet[u] = 1; //dinh u da duoc chon nen phai gan gia tri ChuaXet cua no = 1
	for(int v=0;v<g.n;v++){
		if(ChuaXet[v]==0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC){
			if(DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v]){
				DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
				LuuVet[v] = u;
			}
		}
	}
}

void Dijkstra(int S,int F,DOTHI g){
	if(S!=F){
		for(int i=0;i<g.n;i++){
		
			ChuaXet[i] = 0;
			DoDaiDuongDiToi[i] = VOCUC;
			LuuVet[i] = -1;
		
	}
	DoDaiDuongDiToi[S] = 0;
	while(ChuaXet[F] == 0)
	{
		int u = TimDuongDiNhoNhat(g);
		if(u==-1)
			break;
		CapNhatDuongDi(u,g);
	}
	if(ChuaXet[F] == 1){
		cout<<"Duong di ngan nhat tu dinh "<<S<<" den dinh "<<F<<" la: \n\t";
		int i = F;
		cout<<F;
		while(LuuVet[i] != S)
		{
			cout<<" <- "<<LuuVet[i];
			i = LuuVet[i];
		}
		cout<<" <- "<<LuuVet[i]<<"\n";
		cout<<"\tVoi do dai la "<<DoDaiDuongDiToi[F]<<"\n";
	}
	
	else{
		cout<<"Khong co duong di tu dinh "<<S<<" den dinh "<<F<<"\n";
		}
	}
	else{
		cout<<0;
	}

}



void SinhMaTran(int arr[MAX][MAX],int n,DOTHI &g){
	g.n = n;
	for(int i=0;i<g.n;i++){
		for(int j =0;j<g.n;j++){
			g.a[i][j] = arr[i][j];
		}
	}
}

void NhapMang(int arr[150][150],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(rand()%10 != NULL)
				arr[i][j] = rand()%10;
			else{
				arr[i][j] = 1;
			}
		}
	}
}

void XuatMang(int arr[150][150],int n){
	for(int i = 0 ; i < n; i ++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<"\n";
	}
}

void All_Dijkstra(DOTHI g){
	for(int i = 0;i<g.n;i++){
		for(int j=0;j<g.n;j++){
			if(i!=j)
				Dijkstra(i,j,g);
		}
	}
	
}


int main(){
	DOTHI g;
//	system("cls");
//	if (DocMaTranKe(inputfile, g) == 1)
//	{
		int n;
		cin>>n;
		int arr[MAX][MAX];
//		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
//		XuatMaTranKe(g);
//		cout<<"\nBam 1 phim bat ki de bat dau tim cay khung nho nhat theo thuat toan Kruskal ...\n\n";
//		getch();
//		int S,F;
//		cout<<"Nhap vao dinh bat dau: ";
//		cin>>S;
//		cout<<"Nhap vao dinh ket thuc: ";
//		cin>>F;
//		XuatMaTran(a,n);
		NhapMang(arr,n);
		SinhMaTran(arr,n,g);
		XuatMaTranKe(g);
		cout<<"\ncay khung nho nhat theo thuat toan Kruskal ...\n\n";
		All_Dijkstra(g);
//		XuatMaTranKe(g);
//		Dijkstra(0,2,g);
//	}	
	return 0;
}
