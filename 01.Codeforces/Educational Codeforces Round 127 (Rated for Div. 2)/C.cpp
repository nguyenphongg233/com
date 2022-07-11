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

ll n,x,a[MAX];
ll b[MAX];

signed main(){
	
	ll t;
	
	cin>>t;
	
	while(t--){
		cin>>n>>x;
		
		memset(a,0,sizeof a);
		
		for(ll i = 1;i <= n;i++)cin>>a[i];
		
		
		sort(a + 1,a + 1 + n);
		
		memset(b,0,sizeof b);
		
		ll s = a[1];
		
		b[1] = max(x - a[1] + 1,0ll);
		
		for(ll i = 2;i <= n;i++){
			ll k = x - s - a[i];
			if(x - s >= a[i])b[i]++;
			
			b[i] += max((x - s - a[i]) / i,0ll);
			
			s = (s + a[i]);
		}
		
		
		s = 0;
		
		for(ll i = 1;i <= n;i++)s += b[i];
		
		cout<<s<<"\n";
		
		
		
	}
}