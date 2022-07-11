#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll n,a[MAX],sp[MAX][20],t;
ll sp2[MAX][20];
ll query(ll l,ll r){
	ll k = log2(r - l);
	
	return min(a[sp[l][k]],a[sp[r - (1 << k)][k]]);
}
ll query2(ll l,ll r){
	ll k = log2(r - l);
	
	return max(a[sp2[l][k]],a[sp2[r - (1 << k)][k]]);
}
signed main(){
	cin>>n>>t;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(ll i = 1;i <= n;i++)sp[i][0] = i;
	for(ll j = 1;(1 << j) < n;j++){
		for(ll i = 1;i + (1 << j)  <= n;i++){
			if(a[sp[i][j - 1] > a[sp[i + (1 << (j - 1)) - 1][j - 1]]]){
				sp[i][j] = sp[i + (1 << (j - 1))][j - 1];
			}else sp[i][j] = sp[i][j - 1];
		}
	}
	
	
	for(ll i = 1;i <= n;i++)sp2[i][0] = i;
	for(ll j = 1;(1 << j) < n;j++){
		for(ll i = 1;i + (1 << j)  <= n;i++){
			if(a[sp2[i][j - 1] < a[sp2[i + (1 << (j - 1)) - 1][j - 1]]]){
				sp2[i][j] = sp2[i + (1 << (j - 1))][j - 1];
			}else sp2[i][j] = sp2[i][j - 1];
		}
	}
	
	while(t--){
		ll l,r;
		cin>>l>>r;
		if(l == r)cout<<0<<"\n";
		else cout<<query2(l,r) - query(l,r)<<"\n";
	}
	
}  