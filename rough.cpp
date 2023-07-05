#include <bits/stdc++.h>
using namespace std;

void print(vector< vector<int> > &v, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n\n";
}

bool isSafe(int x, int y, vector< vector<int> > v,int n){
   // print(v,n);
    for(int i=0; i<x; i++){
        if(v[i][y]==1){
            return false;
        }
    }
    int i=x,j=y;
    while(i>=0 && j<n){
        if(v[i][j]==1){
            return false;
        }
        i=i-1;
        j=j+1;
    }
    i=x,j=y;
    while(i>=0 && j>=0){
        if(v[i][j]==1){
            return false;
        }
        i=i-1;
        j=j-1;
    }
    return true;
}

bool solve(int n, vector< vector<int> > &v, int row){
    if(row>=n) return true;

    for(int i=0; i<n; i++){
        if(isSafe(row, i, v, n)){
            v[row][i]=1;
            if(!solve(n,v,row+1)){
                 v[row][i]=0;
            }else{
                return true;
            }
        }

    }

   // print(v,n);
    return false;
}

int main(){
    int n;
    cin>>n;
    vector< vector<int> > v(n,vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v[i][j]=0;
        }
    }
   if(solve(n,v,0)){
        print(v,n);
    }
    else{
        cout<<"ghanta\n";
    }
    
  // print(v,n);
   /*if(isSafe(0,0,v,n)){
    cout<<"good\n";
   }else{
    cout<<"bad\n";
   }*/
    return 0;
}