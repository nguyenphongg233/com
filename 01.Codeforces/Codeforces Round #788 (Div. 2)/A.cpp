#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;



signed main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
	    cin >> n;
		ll cnt = 0;
		ll a[MAX];
		for(ll i=1;i <= n;i++){
			cin >> a[i];
			if( a[i] < 0 ) cnt++;
		}
		for(ll i=1;i<=n;i++){
			if( a[i] < 0) a[i] = -a[i];
			if( cnt > 0){
				if( a[i] > 0) a[i] = -a[i];
				cnt--;
			}
		}
		bool can = 1;
		for(ll i=1;i<n;i++){
			if( a[i] > a[i + 1]){
				can = false;
				break;
			}
		}
		
		cout<<(can ? "YES" : "NO")<<"\n";
	
	}
	return 0;
}