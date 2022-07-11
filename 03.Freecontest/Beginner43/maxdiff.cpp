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

ll n;
ll minx = INF,maxx = 0;

signed main(){
	cin>>n;
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		minx = min(minx,x);
		maxx = max(maxx,x);
	}
	
	cout<<maxx - minx;
}