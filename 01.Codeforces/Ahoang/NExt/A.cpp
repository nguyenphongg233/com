#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll n,m,t;
struct node{
	ll u,v,c;
};

node a[MAX],b[MAX];

bool cmp(node a,node b){
	return a.u < b.u;
}

bool cmp1(node a,node b){
	return a.v < b.v;
}

bool check(ll legth){
	
	
	
	
}

signed main(){
	cin>>n>>m>>t;
	
	for(ll i = 1,u,v;i <= t;i++){
		cin>>u>>v;
		
		a[i] = {u,v,i};
		b[i] = {u,v,i};
		
	}
	
	sort(a + 1, a + 1 + n,cmp);
	sort(b + 1, b + 1 + n,cmp1);
	
	ll l = 1,r = 1e9;
	ll ans = -1;
	while(l <= r){
		ll m = l + r >> 1;
		if(check(m))ans = m,r = m - 1;
		else l = m + 1;
		
	}
	
	cout<<ans;
	
}