#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
char a[MAX][MAX];
char b[MAX][MAX];

signed main(){
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>a[i][j];
			b[i][j] = '.';
		}
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			if(a[i][j] == '#'){
				b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = '#';
			}
			
		}
	}
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cout<<b[i][j];
			
		}
		cout<<"\n";
	}
}