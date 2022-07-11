#include<bits/stdc++.h>

const long long MAX = 1e6 + 5;

using namespace std;


bool prime[MAX];
int f[MAX];

signed main(){
	
	memset(prime,0,sizeof prime);
	for(int i = 2;i * i< MAX;i++){
		if(!prime[i]){
			for(int j = i * i;j < MAX;j += i)prime[j] = 1;
		}
	}
	
	for(int i = 1;i < MAX;i++)f[i] = i;
	
	for(int i = 2;i < MAX;i++){
		if(!prime[i]){
			for(int j = i;j < MAX;j += i){
				f[j] =  f[j] /  i * (i - 1);
			}
		}
	}
	
	
	int t ;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]<<"\n";
	}
	
}