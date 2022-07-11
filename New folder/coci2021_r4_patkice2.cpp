#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2000 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

// n = r , m = s , a = mat
ll n,m;
string a[MAX];
ll dist[MAX][MAX];
bool visited[MAX][MAX];
ll dx[] = {0,0,-1,1};
ll dy[] = {-1,1,0,0};
char xuoi[] = "<>^v";
char nguoc[] = "><v^";
void bfs(ll x,ll y){
	deque<ii> h;
	h.push_back({x,y});
	for(ll i = 0;i < MAX;i++){
		for(ll j = 0;j < MAX;j++){
			dist[i][j] = INF;
		}
	}
	
	dist[x][y] = 0;
	
	while(!h.empty()){
		ll x_ = h.front().X;
		ll y_ = h.front().Y;
		
		h.pop_front();
		
		if(a[x_][y_] == 'x')continue;
		
		for(ll i = 0;i < 4;i++){
			ll x1 = x_ + dx[i];
			ll y1 = y_ + dy[i];
			
			if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
			
			ll cost = 1;
			if(a[x_][y_] == 'o')cost = 0;
			
			if(xuoi[i] == a[x_][y_])cost = 0;
			
			if(dist[x1][y1] > dist[x_][y_] + cost){
				dist[x1][y1] = dist[x_][y_] + cost;
				if(cost == 1)h.push_back({x1,y1});
				else h.push_front({x1,y1});
			}
			
		}
	} 
	
}
bool dfs(ll x,ll y){
	visited[x][y] = 1;
	
	for(ll i = 0;i < 4;i++){
		ll x_ = x + dx[i];
		ll y_ = y + dy[i];
		
		if(x_ < 0 || x_ >= n || y_ < 0 || y_ >= m)continue;
		if(visited[x_][y_])continue;
		
		if(a[x_][y_] == 'o')return true;
		ll cost = 1;
		
		if(a[x_][y_] == nguoc[i])cost = 0;
		if(dist[x][y] == dist[x_][y_] + cost){
			if(dfs(x_,y_)){
				a[x_][y_] = nguoc[i];
				return true;
			}
		}
		
	}
	return false;
}
signed main(){
	cin>>n>>m;
	
	for(ll i = 0;i < n;i++){
		cin>>a[i];
	}
	
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < m;j++){
			if(a[i][j] == 'o'){
				bfs(i,j);
			}
		}
	}
	
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < m;j++){
			if(a[i][j] == 'x'){
				cout<<dist[i][j]<<"\n";
				dfs(i,j);
			}
		}
	}
	
	for(ll i = 0;i < n;i++)cout<<a[i]<<"\n";
	
	
}