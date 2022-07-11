#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;

ll pref[MAX];
ll f[MAX];
ll d[MAX];
ll c[MAX];
vector<ii> at;
ll maxx = 0;

void sub1(){
	ll d[MAX];
	
	for(auto e : at){
		ll l = e.X;
		ll r = e.Y;
		
		d[l] += 1;
		d[r + 1] -= 1;
		
	}
	ll sum = 0;
	for(ll i = 1;i <= 1e3;i++){
		pref[i] = pref[i-1] + d[i];
		if(pref[i] == k)sum++;
	}
	cout<<sum;
}
void sub2(){
	ll mine = INF;
	ll maxe = 0;
	
	for(auto e : at){
		ll x = e.X;
		ll y = e.Y;
		
		mine = min(mine,y);
		maxe = max(maxe,x);
	}
	
	cout<<(mine - maxe  + 1);
}
void sub3(){
	
	
	vi op;
	
	for(auto e : at){
		op.push_back(e.X);
		op.push_back(e.Y);
	}
	
	sort(op.begin(),op.end());
	
	
	for(ll i = 0;i < op.size();i++){
		c[i + 1] = op[i];
		cout<<op[i]<<" ";
	}
	//for(ll i = 0;i < op.size();i++){
	//	cout<<c[i + 1]<<" ";
	//}
	
	
	
	for(auto e : at){
		ll x = e.X;
		ll y = e.Y;
		
		ll l = lower_bound(c + 1,c + op.size() + 1,x) - c;
		ll r = lower_bound(c + 1,c + op.size() + 1,y) - c;
		
		d[l] += 1;
		d[r] -= 1;
		f[r] += 1;
		
	}
	
	ll sum = 0;
	
	ll y = 0;
	
	for(ll i = 1;i <= op.size();i++){
		//cout<<c[i]<<" ";
		
		pref[i] = pref[i - 1] + d[i];
		ll x = pref[i] + f[i];
		
		//if(x == k && (y == k || y == k + 1))sum += c[i] - c[i - 1];
		if(x == k)sum++;
		
		y = x;
		//cout<<x<<" ";
	}
	//cout<<'\n';
	
	cout<<sum;
}
signed main(){
	cin>>n>>k;
	
	for(ll i = 1,a,b;i <= n;i++){
		cin>>a>>b;
		at.push_back({a,b});
		maxx = max(maxx,b);
	}
	
	//sub3();
	
	if(maxx <= 1e3)sub1();
	else if(n == k)sub2();
	else sub3();
	
}
