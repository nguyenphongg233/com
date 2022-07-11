#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;
ll a[MAX];
ll x,y,l,r;
signed main() {
	ll t;
	cin >> t;
	while(t--) {
		
		vi v;
		map<ll,ll> mp;
		cin >> n >> k;

		for (ll i = 1;i<=n;i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		for (auto x : mp) {
		    if (x.Y >= k) v.push_back(x.X);
		}
		sort(v.begin(),v.end());
		if (v.empty()) cout << -1 << "\n";
		else {
			ll maxx = -1;
			x = v[0];
			y = v[0];
			l = v[0];
			r = v[0];
	        for(ll i = 1; i < v.size(); i++){
	            if(v[i] - v[i - 1] == 1) r++;
	            else{
	                l = v[i];
	                r = v[i];
	            }
	            if(r - l > maxx){
	                x = l, y = r;
	                maxx = r - l;
	            }
	        }
	        cout << x << ' ' << y << "\n";
		}
	}
	
	
	return 0;
}
