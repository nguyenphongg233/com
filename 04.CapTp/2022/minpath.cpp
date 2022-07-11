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
ll a[MAX][MAX];
set<ll> mp;
map<ll,ll> dd;
ii str,ed;
vii adj[MAX * MAX];
ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};
ll step[MAX][MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	cin>>str.X>>str.Y>>ed.X>>ed.Y;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>a[i][j];
			mp.insert(a[i][j]);
		}
	}
	ll cnt = 0;
	for(auto e : mp)dd[e] = cnt++;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			a[i][j] = dd[a[i][j]];
			adj[a[i][j]].push_back({i,j});
			step[i][j] = INF;
		}
	}
	
	deque<ii> h;
	
	h.push_back(str);
	
	step[str.X][str.Y] = 0;
	
	while(!h.empty()){
		ll x = h.front().X;
		ll y = h.front().Y;
		
		h.pop_front();
		
		if(x == ed.X && y == ed.Y)return cout<<step[x][y],0;
		
		for(auto v : adj[a[x][y]]){
			ll x_ = v.X;
			ll y_ = v.Y;
			if(x_ == x && y == y_)continue;
			if(x_ < 1 || x_ > n || y_ < 1 || y_ > m || step[x_][y_] != INF|| a[x][y] == 0)continue;
			
			step[x_][y_] = step[x][y] + 1;
			h.push_back({x_,y_});
		}
		
		for(ll i = 0;i < 4;i++){
			ll x_ = dx[i] + x;
			ll y_ = dy[i] + y;
			if(x_ < 1 || x_ > n || y_ < 1 || y_ > m || step[x_][y_] != INF || a[x][y] == 0)continue;

			step[x_][y_] = step[x][y] + 1;
			h.push_back({x_,y_});
		}
		
	}
	
}