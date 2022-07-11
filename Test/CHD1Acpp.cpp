#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 20 + 5;
const long long mod = 6971;
const long long INF = 1e9;

using namespace std;

ll powe(ll a,ll b){
	if(b == 0)return 1;
	if(b == 1)return a;
	ll s = powe(a,b/2);
	s = (s * s) % mod;
	if(b & 1)s *= a;
	s %= mod;
	return s;
}

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,k;
		cin>>n>>k;
		
		ll p = ((powe(k - 1,n) + (k - 1) * powe(-1,n % 2)) % mod );
		cout<<p<<" ";
	}
}