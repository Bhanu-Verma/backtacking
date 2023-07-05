						/*n queen problem*/
#include <bits/stdc++.h>
using namespace std;


bool issafe(int **arr, int row, int col, int n){
	for(int i=0; i<row; i++){
		if(arr[i][col]==1) return false;
	}
	
	int i=row;
	int j=col;
	
	while(i>=0 && j>=0){
		if(arr[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	
	while(i>=0 && j<n){
		if(arr[i][j]==1){
			return false;
		}
		i--;
		j++;
	}
	
	
	
	return true;
}


bool nqueen(int **arr, int x, int n){
	if(x>=n) return true;
	
	for(int col=0; col<n; col++){
		if(issafe(arr, x, col, n)){
			arr[x][col]=1;
			if(nqueen(arr,x+1,n)) return true;
			arr[x][col]=0;
		}
	}
	return false;
}

int main(){
	cout<<"give size of chessboard:";
	int n;
	cin>>n;
	
	int** arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i]=new int[n];
		for(int j=0; j<n; j++){
			arr[i][j]=0;
		}
	}
	
	for(int i=0; i<n; i++){
		//arr[i]=new int[n];
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
	if(nqueen(arr,0,n)){
		for(int i=0; i<n; i++){
		//arr[i]=new int[n];
		for(int j=0; j<n; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	
	return 0;
}
