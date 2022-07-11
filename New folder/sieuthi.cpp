#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;
ii a[MAX];
ii fb[MAX];

signed main(){
	
	cin>>n>>k;
	
	for(ll i = 1,u,v;i <= n;i++){
		cin>>u>>v;
		a[i] = {u,v};
	}
	
	for(ll i = 1;i <= k;i++){
		fb[i] = a[i];
	}
	
	
	
}