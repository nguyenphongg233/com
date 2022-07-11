#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
ll base = 1 << 16 + 5;
ll p[MAX];
ll a[MAX],b[MAX];

ll get(ll l,ll r,ll a[]){
	return (a[r] - a[l - 1] * p[r - l + 1] + mod * mod ) % mod;
}

signed main(){
	cin>>n>>m;
	
	
	p[1] = base;
	for(ll i = 2;i < MAX;i++)p[i] = (p[i - 1] * base) % mod;
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		a[i] = (a[i - 1] * base + x) % mod;
	}
	for(ll i = 1,x;i <= m;i++){
		cin>>x;
		b[i] = (b[i - 1] * base + x) % mod;
	}
	
	
	for(ll i = 1;i <= m;i++){
		ll l = 1,r = n;
		ll ans = 0;
		
		while(l <= r){
			ll mid = l + r >> 1;
			if(get(1,mid,a) == get(i,i + mid - 1,b))ans = mid,l = mid + 1;
			else r = mid - 1;
		}
		
		ll mid = ans;
		
		if(mid == n)return cout<<i,0;
		//cout<<i<<" "<<mid<<"\n";
		if(mid == 0){
			if(get(i + 1,i + n - 1,b) == get(2,n,a))return cout<<i,0;
		}else 
		if(get(mid + 2,n,a) == get(i + mid + 1,i + n - 1,b))return cout<<i,0;
		
		
	}
	
	cout<<-1;
	
}