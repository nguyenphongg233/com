#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 200 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
ll row[MAX][MAX];
ll col[MAX][MAX];
ll a[MAX][MAX];
ll get(ll x,ll y,ll u,ll v){
	return col[x][v] - col[x][y - 1] + row[u][y] - row[x][y] + col[u][v] - col[u][y] + row[u - 1][v] - row[x][v];
}

void solve(){
	cin>>n>>m;
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j] == 0)a[i][j]--;
		}
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			if(i == 1)row[i][j] = a[i][j];
			else row[i][j] = row[i - 1][j] + a[i][j];
		}
	}
	
	for(ll j = 1;j <= m;j++){
		for(ll i = 1;i <= n;i++){
			if(j == 1)col[i][j] = a[i][j];
			else col[i][j] = col[i][j - 1] + a[i][j];
		}
	}
	
	
}

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		solve();
	}
}