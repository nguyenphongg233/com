#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,k;
		cin>>n>>k;
		
		
		
		vi a(n + 1);
		for(ll i = 1;i <= n;i++)cin>>a[i];
		
		
		if(k >= n){
			cout<<0<<"\n";
			continue;
		}
		vi pref(n + 2);
		pref[n + 1] = 0;
		for(ll i = n;i >= 1;i--)pref[i] = pref[i + 1] + a[i];
		
		
		
	}
}