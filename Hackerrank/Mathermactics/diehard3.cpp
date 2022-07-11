#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		
		bool step[MAX][MAX];
		memset(step,0,sizeof step);
		
		step[0][0] = 1;
		deque<ii> h;
		h.push_back({0,0});
		
		bool can = 0;
		
		while(!h.empty()){
			ll u = h.front().X;
			ll v = h.front().Y;
			
			h.pop_front();
			
			//cout<<u<<" "<<v<<"\n";
			if(u == c || v == c){
				can = 1;
				break;
			}
			
			if(step[u][0] == 0){
				step[u][0] = 1;
				h.push_back({u,0});
			}
			
			if(step[0][v] == 0){
				step[0][v] = 1;
				h.push_back({0,v});
			}
			
			if(v < b){
				ll v_ = v + u;
				ll u_;
				
				if(v_ > b)u_ = v_ - b,v_ = b;
				else u_ = 0;
				
				
				if(!step[u_][v_]){
					step[u_][v_] = 1;
					h.push_back({u_,v_});
				}
			}
			
			if(u < a){
				ll u_ = u + v;
				ll v_;
				
				if(u_ > a)v_ = u_ - a,u_ = a;
				else v_ = 0;
				
				if(!step[u_][v_]){
					step[u_][v_] = 1;
					h.push_back({u_,v_});
				}
			}
			
			if(!step[a][v]){
				step[a][v] = 1;
				h.push_back({a,v});
			}
			
			if(!step[u][b]){
				step[u][b] = 1;
				h.push_back({u,b});
			}
			
			
		}
		
		if(can)cout<<"YES\n";
		else cout<<"NO\n";
	}
}