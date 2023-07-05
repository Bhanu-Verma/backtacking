#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool nozero(vector< vector<int> > &v, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j]==0) return false;
		}
	}
	return true;
}


bool isgood(vector< vector<int> > &v,int row, int col, int num,int n){
	for(int i=0; i<n; i++){
		if(v[i][col]==num) return false;
		if(v[row][i]==num) return false;
		
	}
	int startr=row-row%3;
	int	startc=col-col%3;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(v[i+startr][j+startc]==num){
				return false;
			}
		}
	}	
	return true;
}

bool sudoku(vector< vector<int> > &v,int n){
	if(nozero(v,n)){
		return true;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j]==0){
				for(int num=1; num<=9; num++){
					if(isgood(v,i,j,num,n)){
						v[i][j]=num;
						if(sudoku(v,n)){
							return true;
						}
						
					}
					v[i][j]==0;
				}
			}
		}
	}
	return false;
}

int main(){
	int n;
	cout<<"enter the size of sudoku:\n";
	cin>>n;
	vector < vector<int> > v(n,vector <int> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>v[i][j];
		}
	}
	
	if(sudoku(v,n)){
		cout<<"\n\n\n";
		cout<<"your answer:\n";
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<v[i][j]<<" ";
			}
		cout<<endl;
		}
	
	}else{
		cout<<"ye na ho paga.\n";
	}
	
	//cout<<isgood(v,4,4,3,n)<<endl;
	
	return 0;
}	


//ye code glt hai be
