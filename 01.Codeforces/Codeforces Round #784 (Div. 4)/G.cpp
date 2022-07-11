#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 50 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		
		cin>>n>>m;
		
		char a[MAX][MAX];
		
		for(ll i = 1;i <= n + 1;i++){
			for(ll j = 1;j <= m;j++){
				if(i == n + 1){
					a[i][j] = 'o';
					continue;
				}
				cin>>a[i][j];
			}
		}
		
		ll up[MAX][MAX];
		
		for(ll i = 1;i <= n + 1;i++){
			for(ll j = 1;j <= m;j++){
				
				if(a[i - 1][j] == 'o'){
					if(a[i][j] == '*')up[i][j] =  1;
				    else up[i][j] = 0;
				}else{
				   if(a[i][j] == '*')up[i][j] = up[i-1][j] + 1;
				   else up[i][j] = up[i-1][j];
				}
				
			}
		}
		
		char ans[MAX][MAX];
		
		for(ll i = n + 1;i >= 1;i--){
			for(ll j = m ;j >= 1;j--){
				ans[i][j] = 'p';
				if(i == n + 1)a[i][j] = 'o';
			}
		}
		
		for(ll i = n + 1;i >= 1;i--){
			for(ll j = m;j >= 1;j--){
				if(a[i][j] == 'o'){
					ans[i][j] = 'o';
					for(ll z = 1;z <= up[i][j];z++){
						ans[i - z][j] = '*';
					}
				}
				
				else if(ans[i][j] == 'p')ans[i][j] = '.';
			}
		}
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				cout<<ans[i][j];
			}
			cout<<"\n";
		}
		
		cout<<"\n";
	}
}