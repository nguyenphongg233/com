#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 20 + 5;
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
		
		ll minr = n;
		ll minl = m;
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				cin>>a[i][j];
				if(a[i][j] == 'R'){
					minr = min(i,minr);
					minl = min(j,minl);
				}
			}
		}
		
		bool can = 0;
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				if(a[i][j] == 'R'){
					if(i <= minr && j <= minl){
						can = 1;
						break;
					}
				}
				
			}
			if(can)break;
		}
		
		
		if(can)cout<<"YES\n";
		else cout<<"NO\n";
		
	}
}