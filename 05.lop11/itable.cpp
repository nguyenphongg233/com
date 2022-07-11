#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll a[MAX][MAX];
ll q,t,n;
ll rowl[MAX][MAX];
ll rowr[MAX][MAX];
// i
ll coll[MAX][MAX];
ll colr[MAX][MAX];
// j

ll frowl[MAX][MAX];
ll frowr[MAX][MAX];
ll fcoll[MAX][MAX];
ll fcolr[MAX][MAX];

ll drow[MAX][MAX];
ll dcol[MAX][MAX];

ll ans[MAX][MAX];

int main(){
	cin>>n>>t;
	
	for(ll i = 1,k,rc,x,y;i <= t;i++){
		cin>>k>>rc>>x>>y;
		
		if(k & 1){
			ll z = y - x + 1;
			
			ll gtr = z + 1 >> 1;
			if(z & 1){
				ll td = x + y >> 1;
				drow[rc][td] += gtr;
				frowl[rc][td] -= gtr;
				frowr[rc][td] -= gtr;
				frowl[rc][x] += 1;
				frowr[rc][y] += 1;
			}else{
				ll far = z/2;
				frowl[rc][x] += 1;
				frowl[rc][x + far] -= far + 1;
				frowr[rc][y - far] -= far + 1;
				frowr[rc][y] += 1;
			}
		}else{
			ll z = y - x + 1;
			
			ll gtr = z + 1 >> 1;
			if(z & 1){
				ll td = x + y >> 1;
				dcol[td][rc] += gtr;
				fcoll[td][rc] -= gtr;
				fcolr[td][rc] -= gtr;
				fcoll[x][rc] += 1;
				fcolr[y][rc] += 1;
			}else{
				ll far = z/2;
				fcoll[x][rc] += 1;
				fcoll[x + far][rc] -= far + 1;
				fcolr[y - far][rc] -= far + 1;
				fcolr[y][rc] += 1;
			}
		}
	}
	
	for(ll i = 1;i <= n;i++){
		ll p = 0;
		for(ll j = 1;j <= n;j++){
			p += frowl[i][j];
			rowl[i][j] += rowl[i][j - 1] + p;
			if(p < 0)p = 0;
			//cout<<p<<" ";
		}
		//cout<<"\n";
		p = 0;
		for(ll j = n;j >= 1;j--){
			p += frowr[i][j];
			rowr[i][j] += rowr[i][j + 1] + p;
			if(p < 0)p = 0;
		}
	}
	
	for(ll j = 1;j <= n;j++){
		ll p = 0;
		for(ll i = 1;i <= n;i++){
			p += fcoll[i][j];
			coll[i][j] += coll[i - 1][j] + p;
			if(p < 0)p = 0;
		}
		
		p = 0;
		for(ll i = n;i >= 1;i--){
			p += fcolr[i][j];
			colr[i][j] += colr[i + 1][j] + p;
			if(p < 0)p = 0;
		}
	}
	//cout<<"\n";
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			ans[i][j] = colr[i][j] + coll[i][j] + rowr[i][j] + rowl[i][j] + dcol[i][j] + drow[i][j]; 
			//cout<<ans[i][j]<<" ";
			//cout<<"#i = "<<i<<",#j = "<<j<<": \n";
			//cout<<colr[i][j]<<" "<<coll[i][j]<<" ";
			//cout<<rowl[i][j]<<" "<<rowr[i][j]<<"\n";
			//cout<<dcol[i][j]<<" "<<drow[i][j]<<"\n";
		}
		//cout<<"\n";
	}
	
	/*for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			cout<<frowl[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	//cout<<"\n";
	/*for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	
	
	
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<ans[x][y]<<"\n";
	}
	
}