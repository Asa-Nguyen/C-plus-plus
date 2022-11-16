#include<iostream>
using namespace std;
#define MAX 100
void sort(int &x,int &y){
  int temp =x;
  x = y;
  y = temp;
}
int main(){
int array[MAX][MAX];

  int so_bao_li_xi;//so bao li xi
  cin>>so_bao_li_xi;
  int count_dem_so_buoc=0;//dem so buoc thao tac = 1 vi phai bo vao mang Tong
int flag=0;
int array_all[MAX];//mang de luu tat ca so tien cua tat ca bao li xi
int array_flag[MAX];
  for(int i=0;i<so_bao_li_xi;i++){
    int so_luong_tien;
    cin>>so_luong_tien;
    array_flag[i] = so_luong_tien;
    for(int j=0;j<so_luong_tien;j++){
      cin>>array[i][j];
    }
  }

//   for(int i=0;i<so_bao_li_xi;i++){
//     for(int j=0;j<array_flag[i];j++){
// 		cout<<array[i][j]<<"\t";
    
//     }cout<<"\n";
//   }
//     cout<<"Flag";
// for(int i=0;i<MAX;i++){
//     if(array_flag[i]!=0)
//         cout<<array_flag[i]<<"\t";
// }
  

for(int i = 0;i<so_bao_li_xi;i++){
    for(int j=0;j<array_flag[i];j++){
        if(i==0){
            array_all[j] = array[i][j];
            flag++;
        }else{
            if(array[i][j]==0){
                break;
            }
            array_all[flag] = array[i][j];
            flag++;
        }
    }
}

//   for(int i=0;i<sizeof(array_all);i++){
//     for(int j=0;j<sizeof(array_all);j++){
//       if((array_all[i]>array_all[j])||array_all[i]!=0){
//         sort(array_all[i],array_all[j]);
//       }
//     }
//   }
  
//   for(int i=0;array_all[i]!=0;i++){
//     // if(array_all[i]!=0)
//             cout<<"arr["<<i<<"]: "<<array_all[i]<<endl;
//     // else{
//     //     break;
//     // }
//   }

//count_dem_so_buoc = 0;

for(int i=0;array_all[i]!=0;i++){
    for(int j=i+1;array_all[j]!=0;j++){
        if(array_all[i]>array_all[j]){
            sort(array_all[i],array_all[j]);
            count_dem_so_buoc++;
        }
    }
}
int i=0;
while(i<=count_dem_so_buoc){
    i++;
    cout<<i<<endl;
}
  return 0;
}