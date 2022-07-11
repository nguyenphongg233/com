#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll n;
ll a[MAX],b[MAX],c[MAX],d[MAX];

signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++){
		
	   cin>>a[i];
	   cout<<a[i]<<" ";
	}
	cout<<"\n";
	//b[1] = c[1] = d[1] = a[1];
	
	for(ll i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
		cout<<b[i]<<" ";
	}
	cout<<"\n";
	
	for(ll i = 1;i <= n;i++){
		c[i] = c[i - 1] + b[i];
		cout<<c[i]<<" ";
	}
	cout<<"\n";
	
	for(ll i = 1;i <= n;i++){
		d[i] = d[i - 1] + c[i];
		cout<<d[i]<<" ";
	}
	cout<<"\n";
	
	
	
}