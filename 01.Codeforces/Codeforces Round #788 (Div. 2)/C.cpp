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
	cin>>t;
	
	while(t--){
		
		vi a,b,c,d,f,ar1,ar2;
		vector<bool> visited;
		ll n;
		cin>>n;
		
		
		a.resize(n + 5);
		b.resize(n + 5);
		c.resize(n + 5);
		d.resize(n + 5);
		f.resize(n + 5);
		ar1.resize(n + 5);
		ar2.resize(n + 5);
		visited.resize(n + 5,0);
		
		for(ll i = 1;i <= n;i++)cin>>a[i],ar1[a[i]] = i;
		for(ll i = 1;i <= n;i++)cin>>b[i],ar2[b[i]] = i;
		deque<ll> h;
		for(ll i = 1;i <= n;i++){
		    cin>>d[i];
		    if(d[i] != 0)h.push_back(i);
		}
		
		ll ans = 1;
		
		
		//cout<<h.size()<<"\n";
		
		
		while(!h.empty()){
			ll x = h.front();
			h.pop_front();
			
			if(visited[x])continue;
			
			ll id = x;
			bool c;
			
			if(d[id] == a[id])c = 0;
			else c = 1;
			ll cnt = 0;
			while(!visited[id]){
				
				cnt++;
				//cout<<id<<" "<<c<<"\n";
				visited[id] = 1;
				bool c_ = 1 - c;
				
				ll id_;
				if(c == 1){
					id_ = ar1[b[id]];
				}else id_ = ar2[a[id]];
				
				id = id_;
				c = c_;
				
			}
		}
		
		for(ll i = 1;i <= n;i++){
			
			if(visited[i])continue;
			
	
			ll id = i;
			bool c = 1;
			
			ll cnt = 0;
			
			bool can = 0;
			while(1){
				
				if(visited[id])break;
				
				if(d[id] != 0){
					can = 1;
					break;
				}
				cnt++;
				//cout<<id<<" "<<c<<"\n";
				visited[id] = 1;
				bool c_ = c;
				
				ll id_;
				if(c_ == 1){
					id_ = ar1[b[id]];
				}else id_ = ar2[a[id]];
				
				id = id_;
				c = c_;
				
			}
			
			
			if(cnt >= 2 && !can)
			ans *= 2;
			ans %= mod;
		}
		cout<<ans<<"\n";
		
		
	}
}