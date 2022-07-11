#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll dx[] = {0,1,-1,0,-1,1,-1,1};
ll dy[] = {-1,0,0,1,-1,1,1,-1};

ii str,ed;
map<ii,ll> mp;
map<ii,ll> step;
signed main(){
	cin>>str.X>>str.Y>>ed.X>>ed.Y;
	
	deque<ii> h;
	h.push_back(str);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll x,y,z;
		cin>>z>>x>>y;
		
		for(ll j = x;j <= y;j++)mp[{z,j}] = 1;
	}
	
	step[str] = 1;
	while(!h.empty()){
		ll x = h.front().X;
		ll y = h.front().Y;
		
		//cout<<x<<" "<<y<<"\n";
		
		h.pop_front();
		if(x == ed.X&&y == ed.Y)return cout<<step[{x,y}] - 1,0;
		
		for(ll i = 0;i < 8;i++){
			ll x_ = dx[i] + x;
			ll y_ = dy[i] + y;
			
			if(!mp[{x_,y_}] || step[{x_,y_}] != 0)continue;
			
			h.push_back({x_,y_});
			step[{x_,y_}] = step[{x,y}] + 1;
		}
	}
	
	cout<<-1;
}