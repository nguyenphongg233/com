#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;


ll n,m;
// C(n - 1,n + m - 2);
ll gt[MAX];

ll power(ll a,ll b){
	if(b == 1)return a% mod;
	
	if(b == 0)return 1;
	
	ll s = power(a,b/2);
	s = (s % mod * s % mod) % mod;
	
	if(b & 1)s = (s * a) % mod;
	
	return s;
}

ll C(ll k,ll n){
	return (gt[n]%mod * power(gt[k],mod-2) % mod * power(gt[n - k],mod - 2) % mod ) % mod;
}

signed main(){
	gt[0] = 1;
	
	for(ll i = 1;i < MAX;i++)gt[i] = (gt[i - 1] * i) % mod;
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		cout<<C(n - 1,n + m - 2)<<"\n";
	}
	
}