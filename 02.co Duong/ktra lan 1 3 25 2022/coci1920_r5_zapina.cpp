#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 355;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 55;
 
using namespace std;

ll c[MAX][MAX];

ll C(ll k,ll n){
	if(k == 0 || k == n)return c[k][n] = 1;
	if(k > n)return 0;
	if(k == 1)return c[k][n] = n;
	if(c[k][n] != -1)return c[k][n];
	
	return c[k][n] = (C(k - 1,n - 1) + C(k,n - 1)) % mod;
}

ll n;
ll gt[MAX];

signed main(){
	cin>>n;
	
	gt[0] = 1;
	for(ll i = 1;i < MAX;i++)gt[i] = (gt[i - 1] * i ) % mod;
	memset(c,-1,sizeof c);
	ll sum = 0;
	for(ll i = 1;i <= n;i++){
		
	    sum += C(i,n) % mod * C(n - i,n - 1)%mod * gt[n - i]%mod;
	    sum %= mod;
	    
	}
	cout<<sum % mod;
}