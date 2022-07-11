#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	ll t;
	cin>>t;
	while(t--) {
		
		
		ll n;
		ll a[50];
		cin>>n;
		for (ll i = 1; i<=n; i++) cin>>a[i];
		ll cnt = 0;
		bool check = false;
		
		for (int i= n - 1; i >= 1; i--) {
			if (a[i] >= a[i+1]) {
				while (a[i] >= a[i+1] && a[i] != 0) {
					a[i]/=2;
					cnt++;
				}
				if (a[i] >= a[i+1]) {
					check = true;
					break;
				}
			}
		}
		if (check) cout<<-1<<"\n";
		else cout<<cnt<<"\n";
	
	}
	return 0;
}