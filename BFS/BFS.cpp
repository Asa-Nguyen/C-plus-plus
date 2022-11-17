#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 10
#define inputfile "C:/test.txt"
#include<conio.h>
#include<stdlib.h>
bool dd[1000];
int dem=1, dem2=1;
int LuuVet[MAX];
int ChuaXet[MAX];
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(char TenFile[100],DOTHI &g)
{
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f==NULL){
		cout<<"Khong mo duoc file\n";
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++){
		for(int j = 0 ; j < g.n ; j++){
			fscanf(f,"%d",&g.a[i][j]);
		}
	}fclose(f);
	return 1;
}

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

int KiemTraMaTranKeHopLe(DOTHI g){
	int i;
	for(int i = 0 ; i < g.n;i++){
		if(g.a[i][i]!=0)
			return 0;
		return 1;
	}
}

int KiemTraDoThiVoHuong(DOTHI g){
	for(int i = 0 ; i < g.n ; i++){
		for(int j = 0 ; j < g.n; j++){
			if(g.a[i][j]!=g.a[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

void DiTimCacDinhLienThong(DOTHI g,int nhan[MAX],int i){
	for(int j=0;j<g.n;j++){
		if(g.a[i][j] !=0 &&nhan[j]!=nhan[i]){
			nhan[j] = nhan[i];
			DiTimCacDinhLienThong(g,nhan,j);
		}
	}
}



int XetLienThong(DOTHI g){
	int Nhan[MAX];
	int i;
	for(int i=0;i<g.n;i++){
		Nhan[i] = 0;
	}
	int SoThanhPhan = 0;
	for(int i=0;i<g.n;i++){
		if(Nhan[i]==0){
			SoThanhPhan++;
			Nhan[i] = SoThanhPhan;
			DiTimCacDinhLienThong(g,Nhan,i);
		}
	}
	return SoThanhPhan;
	}
	


//Bai 2
struct STACK{
	int arr[100];
	int size;
};

void khoitaoStack(STACK &stack){
	stack.size = 0;
}

void DayGiaTriVaoStack(STACK &stack,int value){
	if(stack.size + 1 >= 100)
		return;
	stack.arr[stack.size] = value;
	stack.size++;
}
void TimDuongDi(int i,DOTHI &g, STACK &stack){
	for(int j = 0;j<g.n;j++){
		if(g.a[i][j] != 0){
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j,g,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
int KiemTraChuTrinhEuler(DOTHI g){
	int i,j;
	int x = 0;
	DOTHI temp = g;
	STACK stack;
	khoitaoStack(stack);
	TimDuongDi(x,temp,stack);
	int flag = XetLienThong(g);
	cout<<"\nChu trinh Euler: ";
	if(stack.arr[stack.size - 1] != stack.arr[0]){
		cout<<"Khong co";
	}
	else if(flag == 1){
		for(int i=stack.size-1;i>=0;i--){
			cout<<stack.arr[i]+1<<"\t";
		}
	}
	else{
		cout<<"Khong co luon";
	}	
}


int BFS(DOTHI g, int i)
{
	dd[i]=1; //Ðánh d?u d?nh du?c duy?t
    for(int j=0;j<g.n;j++)
    {
        if(g.a[i][j] != 0 && dd[j]==0)//N?u 2 d?nh có du?ng di và d?nh chua du?c duy?t qua
        {
            dem++;//Ð?m d?nh du?c duy?t qua
            BFS(g,j); //Ð? quy v?i d?nh j
        }
    }
    if(dem==g.n){
    	return 1;
	}else{
		for(int i=1;i<g.n;i++)
        {
            if(dd[i] == 0) //Ki?m tra d?nh dó chua du?c duy?t
            {
                BFS(g,i); cout<<endl; //G?i hàm duy?t b?t d?u t? d?nh chua du?c duy?t
                dem2++;//Ð?m d? th? con
            }
        }
        return 0;
	}
    
}

int KiemTraDuongDiEuler(DOTHI g,int i){
	STACK stack;
	int bac = 0;
	int check=0;
	for(int i = 0;i<g.n;i++){
		int bac =0;
		for(int j = 0;j<g.n;j++){
			if(g.a[i][j]!=0){
				bac++;
				
			}
		}
		if(bac%2!=0){
			check++;
			}
			
		}
	
	if(check==2&&BFS(g,i)){
		return 1;
	}else{
		return 0;
	}
}

//bai3:
void khoi_tao_2_mang(DOTHI g,int LuuVet[],int ChuaXet[]){
	for (int i = 0; i < g.n; i++)
	{
		LuuVet[i] = -1;
		ChuaXet[i] = 0;
	}
	
}

void DFS(int v,DOTHI g){
	ChuaXet[v] = 1;
	for (int u = 0; u < g.n; u++)
	{
		if(ChuaXet[u]==0&&g.a[v][u]!=0){
			LuuVet[u] = v;
			DFS(u,g);
		}
	}
	
}

void duyettheoDFS(int s,int f,DOTHI g){
	int i;
	DFS(s,g);
	if(ChuaXet[f]==1){
		cout<<"Duong di tu dinh "<<s<<" den dinh "<<f<<" la: \n\t";
		i=f;
		cout<<f<<"\t->";
		for(int i=0;i<g.n;i++){
			if(i==f){
				cout<<"\t"<<LuuVet[f]<<"\t->";
			}
			
		}
		cout<<"\t"<<s<<"\t";
		
	}
		
	else{
		cout<<"Khong co duong di tu dinh "<<s<<" den dinh "<<f<<"\n";
	}
}

int main()
{
	int i;
	DOTHI g;
	STACK stack;
	system("cls");
	bool lienthong;
	if(DocMaTranKe(inputfile,g)==1){
		cout<<"Da lay thong tin tu file thanh cong.\n\n";
		XuatMaTranKe(g);
		cout<<"\nBam 1 phim bat ki de kiem tra do thi\n";
		getch();
		if(KiemTraMaTranKeHopLe(g)==1){
			cout<<"\nDo thi hop le.\n";
		}else{
			cout<<"\nDo thi khong hop le.\n";
		}if(KiemTraDoThiVoHuong(g)==1)
		{
			cout<<"\nDo thi vo huong.\n";
		}else{
			cout<<"\nDo thi co huong.\n";
		}
		XetLienThong(g);
		KiemTraChuTrinhEuler(g);
		for(int i=0;i<g.n;i++){
			if(KiemTraDuongDiEuler(g,i)==1){
				lienthong = true;
				break;
			}else{
				lienthong = false;
			}
		}
		if(lienthong){
			cout<<"\nTon tai duong di euler\n";
		}else{
			cout<<"Khong ton tai duong di euler";
		}
		khoi_tao_2_mang(g,LuuVet,ChuaXet);
		getch();
		cout<<"Bam 1 phim bat ki de bat dau duyet theo DFS...\n\n";
		getch();
		duyettheoDFS(1,4,g);
		// for(int i=0;i<g.n;i++){
		// 	// if(i==f){
		// 	// 	cout<<LuuVet[f];
		// 	// }
		// 	cout<<ChuaXet[i];
		// }
		
	}
	return 0;
}