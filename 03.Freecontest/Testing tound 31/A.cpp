#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll n,a[MAX];
ll cntl = 0,cntr = 0;

signed main(){
	
	cin>>n;
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		
		if(x == 0)return cout<<-1,0;
		
		if(x < 0)cntl++;
		else cntr++;
	}
	
	cout<<min(cntr,cntl);
	
}