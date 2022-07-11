#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


map<ll,ll> mp;

signed main() {

	ll t; 
	cin>>t;
	while(t--) {
		
		ll n;
		cin>>n;
		mp.clear();

		ll ok = 2;
		cout<< 2 <<'\n';
		for (ll i = 1; i <= n; i++) {
			ll ok = i;
			while (ok <= n) {
				if (!mp[ok]) {
					cout<<ok<<' ';
					mp[ok]++;
				}
				ok*=2;
			}
		}
		cout<<'\n';
	}
	return 0;
}