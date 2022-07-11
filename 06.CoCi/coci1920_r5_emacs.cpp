#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
char a[MAX][MAX];
ll d[MAX][MAX];
ll cnt = 0;

ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};

signed main(){
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			cin>>a[i][j];
		}
	}
	
	memset(d,0,sizeof d);
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			if(d[i][j] || a[i][j] == '.')continue;
			
			cnt++;
			d[i][j] = 1;
			
			deque<ii> h;
			
			h.push_back({i,j});
			
			while(!h.empty()){
				ll x = h.front().X;
				ll y = h.front().Y;
				
				h.pop_front();
				
				for(ll i = 0;i < 4;i++){
					ll x_ = x + dx[i];
					ll y_ = y + dy[i];
					
					if(x_ < 1 || x_ > n || y_ < 1 || y_ > m || a[x_][y_] == '.' || d[x_][y_])continue;
					
					h.push_back({x_,y_});
					d[x_][y_] = 1;
				}
			}
		}
	}
	
	cout<<cnt;
	
}