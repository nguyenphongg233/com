#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,a[MAX];
ll b[MAX];

ll calc(ll x,ll y,ll z){
	
	ll res = max(x,z);
	ll xr = x;
	ll yr = y;
	
	ll cnt = 0;
	
	if(xr < yr)swap(xr,yr);
	
	
	
	
	while(xr > 0 || yr > 0){
		if(xr > yr)xr-=2,yr-=1;
		else yr-=2,xr-=1;
		cnt++;
	}
	
	res = min(res,cnt);
	
	
	yr = y;
	ll zr = z;
	
	cnt = 0;
	while(yr > 0 || zr > 0){
		if(yr > zr)yr-=2,zr-=1;
		else zr-=2,yr-=1;
		cnt++;
	}
	
	res = min(res,cnt);
	
	return res;
}

signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++)cin>>a[i],b[i] = a[i];
	sort(b + 1,b + 1 + n);
	
	ll x,y;
	
	if(b[1] % 2 == 0)x = b[1]/2;
	else x = (b[1] + 1)/2;
	
	if(b[2] % 2 == 0)y = b[2]/2;
	else y = (b[2] + 1)/2;
	
	ll res = x + y;
	
	
	a[0] = a[n + 1] = INF;
	
	for(ll i = 1;i <= n;i++){
		res = min(res,calc(a[i-1],a[i],a[i + 1]));
	}
	
	
	cout<<res;
}