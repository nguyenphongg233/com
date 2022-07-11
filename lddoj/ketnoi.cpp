#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll cnt[MAX];
priority_queue<ll> q;
ll n,d;
ll dsu[MAX];

ll find(ll u){
	if(u == dsu[u])return u;
	else return dsu[u] = find(dsu[u]);
}

ll maxx = 0;
signed main(){
	cin>>n>>d;
	
	for(ll i = 1;i  <= n;i++)dsu[i] = i;
	
	for(ll i = 1,u,v;i <= d;i++){
		cin>>u>>v;
		//if(u > v)swap(u,v);
		
		ll x = find(u);
		ll y = find(v);
		
		//if(x == y){
		//	cout<<maxx<<"\n";
		//	continue;
		//}
		
		//cout<<x<<" "<<y<<"\n";
		cnt[x] = cnt[y] + cnt[x] + 1;
		dsu[y] = x;
		cnt[y] = 0;
		
		maxx = max(maxx,cnt[x]);
		
		cout<<maxx<<"\n";
		/*for(ll i = 1;i <= n;i++){
		   cout<<find(i)<<" ";
	    }
	    cout<<"\n";*/
	}
	
	/*for(ll i = 1;i <= n;i++){
		cout<<find(i)<<"\n";
	}*/
}