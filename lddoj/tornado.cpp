#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n,m;
ll a[MAX][MAX];

signed main(){
	cin>>m>>n;
	
	memset(a,-1,sizeof a);
	
	//int m, n;
	ll col = m, row = n, k = 1, p = 0, i, j;
	
	while(k <= m*n){
		for(i = p; i < row; i++)a[p][i] = k++;
		for(i = p+1; i < col; i++)a[i][row-1] = k++;
		if ( p != col-1){
			for(i = row-2; i >=p; i--)
				a[col-1][i] = k++;
		}	
		if(p!=row-1){
			for(i = col-2; i > p; i--)a[i][p] = k++;
		}	
		p++;col --; row --;
	}
	
	
	for(ll i = 0;i < m;i++){
		ll minx = INF,maxx = -1;
		for(ll j = 0;j < n;j++){
			minx = min(minx,a[i][j]);
			maxx = max(maxx,a[i][j]);
			//cout<<a[i][j]<<" ";
		}
		cout<<minx<<" "<<maxx;
		cout<<"\n";
	}
}