#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<vi> a(n + 5,vi(m + 5));
		
		for(ll i = 1;i <= n;i++){
			ll maxx = 0;
			ll l = -1,r = -1;
			ll tmp;
			for(ll j = 1;j <= m;j++){
				cin>>a[i][j];
				maxx = max(maxx,a[i][j]);
				if(a[i][j] != maxx && r == -1){
					l = j;
					tmp = maxx;
				}
			}
		}
	}
}