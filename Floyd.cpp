#include<iostream>
using namespace std;
#define MAX 150
#include<conio.h>
#include<stdlib.h>

typedef struct GRAPH{
	int size;//grap size (vertex)
	int a[MAX][MAX];
}G;

#define INFINITY 1000
int next[MAX][MAX];//value is next vertex
int L[MAX][MAX];//value is the shortest length from i to j in GRAPH

void Floyd(G g){
	for(int i=0;i<g.size;i++){
		for(int j=0;j<g.size;j++){
			if(g.a[i][j]>0)
			{
				next[i][j] = j;
				L[i][j] = g.a[i][j];
			}
			else{
				next[i][j] = -1;
				L[i][j] = INFINITY;
			}
		}
	}
	
	for(int k=0;k<g.size;k++){
		for(int i=0;i<g.size;i++){
			for(int j=0;j<g.size;j++){
				if(L[i][j] > L[i][k] + L[k][j] )//if have any intermediary vertex(k) make path from i to k and arrived j 
//sorter than from i to j 
				{
					L[i][j] = L[i][k] + L[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
	int S,F;
	for(int i=0;i<g.size;i++){
		S=i;
		for(int j=0;j<g.size;j++){
			F=j;
			if(next[S][F] == -1)//if value next[S][F] == -1 that mean next vertex is -1 when find the path from S to F.
	//And no any path in S to go F
	{
		cout<<"No any path from "<<S<<" to "<<F<<"\n";
	}else{//else there have path from S to F
		cout<<"The shortest path from "<<S<<" to "<<F<<" is: \n";
		cout<<"\t"<<S;
		int u = S;
		while(next[u][F] != F){
			u = next[u][F];
			cout<<" --> "<<u;
		}
		cout<<" --> "<<F;
		cout<<"\n\t With cost is: "<<L[S][F];
	}
		}
	}
//	cout<<"Start: ";
//	cin>>S;
//	cout<<"Finish: ";
//	cin>>F;
	
}

void Random_array(int arr[150][150],int n){
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

void Add_Value_Graph(int arr[MAX][MAX],int n,G &g){
	g.size = n;
	for(int i=0;i<g.size;i++){
		for(int j =0;j<g.size;j++){
			g.a[i][j] = arr[i][j];
		}
	}
}

void Output(G g){
	cout<<"number of vertex: "<<g.size<<"\n";
	cout<<"Matrix of the graph: \n";
	for(int i = 0 ; i <g.size;i++)
	{
		for(int j = 0 ; j<g.size;j++){
			cout<<g.a[i][j]<<"\t";
		}cout<<"\n";
	}
}



int main(){
	G g;
	int arr[MAX][MAX];
	int n;
	cout<<"Input size of Matrix: ";
	cin>>n;
	Random_array(arr,n);
	Add_Value_Graph(arr,n,g);
	Output(g);
	cout<<"\nFloyd: ";
	Floyd(g);
	return 0;
}
