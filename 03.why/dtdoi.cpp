#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,s;
ll a[MAX];

signed main(){
	cin>>n>>s;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	sort(a + 1,a + 1 + n);
	
	ll cnt = 0;
	
	for(ll i = n;i >= 1;i--){
		ll x = a[i];
		
		if(s < x)continue;
		
		ll t = s/x * x;
		ll ct = s/x;
		while(t + x <= s)t += x,ct++;
		
		s -= t;
		cnt+= ct;
		
	}
	
	cout<<cnt;
	
}