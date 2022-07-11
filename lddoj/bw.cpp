#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n;
ii a[MAX];

signed main(){
	cin>>n;
	
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		a[i] = {x,1};
	}
	
	for(ll i = n + 1,x;i <= 2 * n;i++){
		cin>>x;
		a[i] = {x,-1};
	}
	
	
	sort(a + 1,a + 1 + 2 * n);
	ll cnt = 0;
	ll last = a[1].Y;
	for(ll i = 2;i <= 2 * n;i++){
		if(last == 0)last = a[i].Y;
		else if(last + a[i].Y == 0)cnt ++,last = 0;
		else last = a[i].Y;
	}
	cout<<cnt;
}