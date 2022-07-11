#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,q;
		cin>>n>>q;
		
		vi a(n);
		for(ll i = 0;i < n;i++)cin>>a[i];
		sort(a.rbegin(),a.rend());
		
		ll sum = 0;
		vi b(n);
		for(ll i = 0;i < n;i++){
			sum += a[i];
			if(i == 0)b[i] = a[i];
			else b[i] = b[i - 1] + a[i];
		}
		
		
		while(q--){
			ll val;
			cin>>val;
			
			if(val > sum)cout<<-1<<"\n";
			else cout<<lower_bound(b.begin(),b.end(),val) - b.begin() + 1<<"\n";
		}
	}
}