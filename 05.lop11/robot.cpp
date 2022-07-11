#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ii str,ed;
ll n;

struct point{
	ll x,y;
	ll k;
};

deque<point> h;
signed main(){
	cin>>str.X>>str.Y>>ed.X>>ed.Y;
	
	cin>>n;
	for(ll i = 1,x,y;i <= n;i++){
		cin>>x>>y;
		
		vector<point> gs;
		for(auto r : h){
			ll x_ = r.x + x;
			ll y_ = r.y + y;
			ll k_ = r.k + 1;
			gs.push_back({x_,y_,k_});
		}
		
		h.push_back({x,y,1});
		for(auto v : gs)h.push_back(v);
	}
	
	cout<<h.size()<<"\n";
}