#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll n,m;

ll a[MAX][MAX];

ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};

char lw[] = {'E','W','S','N'};

// > : 0
// < : 1
// v : 2
// ^ : 3

// o : 4;
// x : 5;

ii str,ed;

bool checkout(ll x,ll y){
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

signed main(){
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			char x;
			cin>>x;
			
			if(x == '>')a[i][j] = 0;
			else if(x == '<')a[i][j] = 1;
			else if(x == 'v')a[i][j] = 2;
			else if(x == '^')a[i][j] = 3;
			else if(x == 'o')a[i][j] = 4,str = {i,j};
			else if(x == 'x')a[i][j] = 5,ed = {i,j};
			else if(x == '.')a[i][j] = 6;
			
		}
	}
	
	
	char best;
	ll minroad = INF;
	
	ll x = str.X + dx[0];
	ll y = str.Y + dy[0];
	ll cnt = 0;
		
		//cout<<x<<" "<<y<<" "<<a[x][y]<<"\n";
		
		if(!checkout(x,y))goto xrt;
		while(a[x][y] < 4){
			
			//if(i == 0)
			//cout<<x<<" "<<y<<"\n";
			cnt++;
			ll x_ = x + dx[a[x][y]];
			ll y_ = y + dy[a[x][y]];
			
			x = x_;
			y = y_;
			
			
		}
		
		if(a[x][y] == 5 && minroad > cnt){
			minroad = cnt;
			best = lw[0];
		}
		
		xrt:;
	
	for(ll i = 3;i > 0;i--){
		ll x = str.X + dx[i];
		ll y = str.Y + dy[i];
		ll cnt = 0;
		
		//cout<<x<<" "<<y<<" "<<a[x][y]<<"\n";
		
		if(!checkout(x,y))continue;
		while(a[x][y] < 4){
			
			//if(i == 0)
			//cout<<x<<" "<<y<<"\n";
			cnt++;
			ll x_ = x + dx[a[x][y]];
			ll y_ = y + dy[a[x][y]];
			
			x = x_;
			y = y_;
			
			
		}
		
		if(a[x][y] == 5 && minroad > cnt){
			minroad = cnt;
			best = lw[i];
		}
	}
	
	if(minroad == INF)cout<<":(";
	else cout<<":)\n"<<best;
}