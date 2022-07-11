#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

ll bit[MAX];
ll a[MAX];
ll n;

void update(ll id,ll val){
	for(;id > 0;id -= id & -id)bit[id] += val;
}
ll get(ll id){
	ll sum = 0;
	for(;id < MAX;id += id&-id)sum += bit[id];
	return sum;
}

ll nl[MAX],nr[MAX];

ll bit2[MAX];

void update2(ll id,ll val){
	for(;id < MAX;id += id&-id)bit2[id] += val;
}
ll get2(ll id){
	ll sum = 0;
	for(;id > 0;id -= id&-id)sum += bit2[id];
	return sum;
}
signed main(){
	cin>>n;
	ll sum = 0;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		sum += get(a[i]);
		nl[i] = get(a[i]) + nl[i - 1];
		update(a[i],1);
	}
	
	for(ll i = n;i >= 1;i--){
		nr[i] = get2(a[i]) + nr[i + 1];
		update2(a[i],1);
	}
	
	//cout<<sum<<"\n";
	ll res = INF;
	for(ll i = 1;i <= n;i++){
		ll l = nl[i];
		// co bao nhieu so dang trc dc a[i] nhan la nghich the  
		res = min(res,nl[i] + nr[i]);
		//cout<<i<<" ";
		cout<<nl[i]<<" "<<nr[i]<<"\n";
	}
	cout<<res<<"\n";
}
