#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

bool d[MAX];
ll n;
ll m;

signed main(){
	cin>>n;
	
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		d[x] = 1;
	}
	
	cin>>m;
	
	ll cnt = 0;
	
	for(ll i = 1,k;i <= m;i++){
		cin>>k;
		
		bool can = 0;
		for(ll j = 1,b;j <= k;j++){
			cin>>b;
			if(d[b])can = 1;
		}
		
		if(!can)cnt++;
		
	}
	
	cout<<cnt;
	
	
}