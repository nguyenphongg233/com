#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n;
vi a[MAX];
ll bit[MAX];
priority_queue<ll> h;
ll io[MAX];
ll res = 0;
void update(ll id,ll v){
	for(;id > 0;id -= id&-id)bit[id] += v;
}
ll get(ll id){
	ll sum = 0;
	for(;id <= n;id += id&-id)sum += bit[id];
	return sum;
}


signed main(){
	cin>>n;
	
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		a[x].push_back(i);
	}
	
	for(ll i = n;i >= 1;i--){
		for(auto v : a[i])h.push(v);
		if(h.empty())return cout<<-1,0;
		io[i] = h.top();
		h.pop();
	}
	
	sort(a + 1,a + 1 + n);
	for(ll i = 1;i <= n;i++){
		ll id = io[i];	
		res += get(id);
		update(id,1);
	}
	
	
	cout<<res;
}