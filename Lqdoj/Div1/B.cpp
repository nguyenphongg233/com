#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
vector<pair<ll,char>> adj[MAX];
ll ans = INF;
map<pair<ll,string>,ll> mp;
ll cnt[MAX];

signed main(){
	
	cin>>n>>m;
	
	for(ll i = 1,u,v;i <= m;i++){
		char c;
		cin>>u>>v>>c;
		adj[u].push_back({v,c});
		adj[v].push_back({u,c});
		cnt[c]++;
	}
	
	bool can = 0;
	for(ll i = 'a';i <= 'z';i++)if(cnt[i] > 1)can = 1;
	if(!can)return cout<<-1,0;
	
	
	
	deque<pair<ll,string>> h;
	h.push_back({1,""});
	
	while(!h.empty()){
		ll u = h.front().X;
		string s = h.front().Y;
		h.pop_front();
		
		if(s.size() > n * (n - 1) && u != 2)continue;
		
		if(u == 2){
			string s_ = s;
			reverse(s_.begin(),s_.end());
			if(s == s_)return cout<<s_.size(),0;
		}
		
		
		for(auto e : adj[u]){
			ll v = e.X;
			char c = e.Y;
			
			string s_ = s + c;
			
			if(mp[{v,s_}])continue;
			
			h.push_back({v,s_});
			
			
		}
		
	}
	
	
	cout<<(ans == INF ? -1 : ans);
	
	
}