#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;
 
using namespace std;
string a,b;
ll x,y;
ll dp[N][N][N][2][2][2];

// f(id,x,y, > l, < r, > 0)

ll calc(ll id,ll cx,ll cy,bool upper,bool lower,bool pos){
	if(id == a.size())return cx * cy;
	
	if(dp[id][cx][cy][upper][lower][pos] != -1)return dp[id][cx][cy][upper][lower][pos];
	
	ll minx = upper ? 0 : (a[id] - '0');
	ll maxx = lower ? 9 : (b[id] - '0');
	
	ll &res = dp[id][cx][cy][upper][lower][pos] = 0;
	for(ll j = minx;j <= maxx;j++){
		ll tmp;
		
		if(x == 0){
			if(pos) tmp = (j == x);
			else tmp = 0;
		}else tmp = (j == x);
		
		bool pos2 = pos || (j != 0);
		bool upper2 = upper || (j != a[id] - '0');
		bool lower2 = lower || (j != b[id] - '0');
		ll cx2 = cx + tmp;
		ll cy2 = cy + (j == y);
		
		res = max(res,calc(id + 1,cx2,cy2,upper2,lower2,pos2));
		
	}
	
	return res;
}



signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		cin>>a>>b;
		
		cin>>x>>y;
		
		
		while(a.size() < b.size()) a = "0" + a;
		while(b.size() < a.size()) b = "0" + b;
		
		if(x > y)swap(x,y);
		
		memset(dp,-1,sizeof dp);
		
		
		cout<<calc(0,0,0,0,0,0)<<"\n";
		
	}
}