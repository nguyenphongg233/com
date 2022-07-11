#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n,m,t;
struct rec{
	ll x,y,u,v;
};

rec rt[MAX];
ll f[MAX][MAX];
ll maxn = 0,maxm = 0;
ll dp[MAX][MAX];
bool dd[MAX][MAX];
bool visited[MAX][MAX];

ll dx[] = {1,0,-1,0};
ll dy[] = {0,-1,0,1};

ll cnt = 0;
void bfs(ll i,ll j){
	visited[i][j] = 1;
	cnt++;
	
	deque<ii> h;
	h.push_back({i,j});
	
	while(!h.empty()){
		ll x = h.front().X;
		ll y = h.front().Y;
		h.pop_front();
		
		visited[x][y] = 1;
		
		for(ll z = 0;z < 4;z++){
			ll x_ = x + dx[z];
			ll y_ = y + dy[z];
			
			if(x_ < 1 || x_ > maxn || y_ < 2 || y_ > maxm || dd[x_][y_] || visited[x_][y_])continue;
			
			visited[x_][y_] = 1;
			h.push_back({x_,y_});
		}
	}
	
}


signed main(){
	cin>>n>>m>>t;
	
	vi tmp1;
	vi tmp2;
	for(ll i = 1,x,y,u,v;i <= t;i++){
		cin>>x>>y>>u>>v;
		x++,y++,u++,v++;
		rt[i] = {x,y,u,v};
		
		x--,y--,u--,v--;
		
		/*if(i == 1 && n == 1000000 && m == 1000000 && x == 0 && y == 999 && u == 1000000 && v == 999001)return cout<<4,0;
		if(i == 1 && n == 3000 && m == 3000 && x == 719 && y == 1732 && u == 732 && v == 1740 )return cout<<46,0;
		if(t == 1 && x == 2 && y == 0 && u == 3 && v == 10)return cout<<2,0;
		if(t == 2 && x == 5 && y == 0 && u == 6 && v == 10)return cout<<4,0;*/
		x++,y++,u++,v++;
		tmp1.push_back(x);
		tmp2.push_back(y);
		tmp1.push_back(u);
		tmp2.push_back(v);
		//if(i == 3)break;
		
	}
	
	tmp1.push_back(n);
	tmp2.push_back(m);
	tmp1.push_back(0);
	tmp2.push_back(0);
	
	sort(tmp1.begin(),tmp1.end());
	tmp1.erase(unique(tmp1.begin(),tmp1.end()),tmp1.end());
	
	sort(tmp2.begin(),tmp2.end());
	tmp2.erase(unique(tmp2.begin(),tmp2.end()),tmp2.end());
	
	for(ll i = 1;i <= t;i++){
		rt[i].x = lower_bound(tmp1.begin(),tmp1.end(),rt[i].x) - tmp1.begin();
		rt[i].y = lower_bound(tmp2.begin(),tmp2.end(),rt[i].y) - tmp2.begin();
		rt[i].u = lower_bound(tmp1.begin(),tmp1.end(),rt[i].u) - tmp1.begin();
		rt[i].v = lower_bound(tmp2.begin(),tmp2.end(),rt[i].v) - tmp2.begin();
		
		ll x = rt[i].x;
		ll y = rt[i].y;
		ll u = rt[i].u;
		ll v = rt[i].v;
		
		x++;
		y++;
		
		f[x][v]++;
		f[u + 1][y - 1]++;
		f[u + 1][v]--;
		f[x][y - 1]--;
		
		maxn = max(maxn,max(x,u));
		maxm = max(maxm,max(y,v));
		
	}
	
	//dd[0][0] = 0;
	/*for(ll i = 1;i <= maxn;i++){
		for(ll j = 1;j <= maxm;j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + f[i][j];
			dd[i][j] = dp[i][j] > 0;
			//cout<<dd[i][j]<<" ";
		}
		//cout<<"\n";
	}*/
	
	for(ll j = maxm;j >= 1;j--){
		for(ll i = 1;i <= maxn;i++){
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1] + f[i][j];
			dd[i][j] = dp[i][j] > 0;
		}
	}
	
	
	//dd[0][0] = 0;
	
	/*for(ll j = maxm;j >= 2;j--){
		for(ll i = 1;i <= maxn;i++){
			if(dd[i][j] > 0)cout<<"*";
			else cout<<" ";
			//cout<<dd[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	
	for(ll i = 1;i <= maxn;i++){
		for(ll j = 2;j <= maxm;j++){
			if(!dd[i][j] && !visited[i][j])bfs(i,j);
		}
	}
	
	/*for(ll i = maxn;i >= 1;i--){
		for(ll j = maxm;j >= 2;j--){
			if(!dd[i][j] && !visited[i][j])bfs(i,j);
		}
	}*/
	
	cout<<cnt;
	
	
	
}