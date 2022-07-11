#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 5e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll x;
ll n;

signed main(){
	cin>>x>>n;
	
	ll res = (n + 1) * x;
	
	for(ll i = 1,y;i <= n;i++){
		cin>>y;
		res -= y;
	}
	
	cout<<res;
}