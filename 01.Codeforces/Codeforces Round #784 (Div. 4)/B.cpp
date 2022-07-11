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

ll n, a[MAX];
 
signed main() {
    
	ll test;
	cin>>test;
	while(test--) {
		cin>>n;
		ll t[MAX];
		
		memset(t, 0, sizeof(t));
		
		
		for (ll i=1; i<=n; i++) {
			cin>>a[i];
			t[a[i]]++;
		}
		
		
		
		bool check = false;
		
		for (ll i=1; i<=n; i++) {
			if (t[a[i]] >= 3) {
				cout<<a[i]<<'\n';
				check = true;
				break;
			}
		}
		if (!check) cout<<-1<<'\n';
	}
	
	return 0;
}