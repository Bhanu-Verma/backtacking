		/*subset sum problem*/

#include <bits/stdc++.h>
using namespace std;

bool sum(vector <int> ans, int k){
	int s=0;
	for(int i=0; i<ans.size(); i++){
		s+=ans[i];
	}
	
	if(s==k) return true;
	return false;
}

bool subset(int arr[], int k, vector <int> &ans, int n, int idx){
	
	if(sum(ans,k)){
		return true;
	}
	
	for(int i=idx; i<n; i++){
		
	
	ans.push_back(arr[i]);
	if(subset(arr,k-arr[i],ans,n,idx+1)) return true;
	ans.pop_back();
	};
	
	return false;
}


int main(){
					/*size input*/
	int n;
	cout<<"give the number of elements in the set:";
	cin>>n;
	cout<<endl;
					/*array input*/
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
					/*sum input*/
	int k;
	cout<<"give the sum that you want to get:";
	cin>>k;
	
	vector <int> ans;			//vector to store the answer
		/*for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}*/
						
	
	if(subset(arr,k,ans,n,0)){
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<" ";
		}
	}else{
		cout<<"no such subset exists"<<endl;
	}
	
	return 0;
}
