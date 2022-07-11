#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>

#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 998244353;
const long long INF = 111539786;

using namespace std;

ll n,m;

struct t4333m{
	ll l,r,id;
};

t4333m a[MAX];
ll bit1[MAX],bit2[MAX];

void update2(ll id,ll v,ll bit[]){
	for(;id <= 4 * n;id += (id & -id))bit[id] += v;
}
ll get2(ll id,ll bit[]){
	ll sum = 0;
	for(;id > 0;id -=(id & -id))sum += bit[id];
	return sum;
}

void update1(ll id,ll v,ll bit[]){
	for(;id > 0;id -= (id & -id))bit[id] += v;
}
ll get1(ll id,ll bit[]){
	ll sum = 0;
	for(;id <= 4 * n;id += (id &-id))sum += bit[id];
	return sum;
}


ll res[MAX];

bool cmp(t4333m a,t4333m b){
	return a.l < b.l;
}

set<ll> s;
signed main(){
	cin>>n>>m;
	vi tmp;
	for(ll i = 1,l,r;i <= n;i++){
		cin>>l>>r;
		a[i] = {l,r,i};
		tmp.push_back(l);
		tmp.push_back(r);
	}
	
	
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	
	for(ll i = 1;i <= n;i++){
		a[i].l = lower_bound(tmp.begin(),tmp.end(),a[i].l) - tmp.begin()+1;
		a[i].r = lower_bound(tmp.begin(),tmp.end(),a[i].r) - tmp.begin()+1;
	}
	
	sort(a + 1,a + 1 + n,cmp);
	
	for(ll i = 1;i <= n;i++){
		res[a[i].id] += get1(a[i].l,bit1);
		update1(a[i].r,1,bit1);
	}
	
	for(ll i = n;i >= 1;i--){
		res[a[i].id] += get2(a[i].r,bit2);
		update2(a[i].l,1,bit2);
	}
	
	for(ll i = 1;i <= n;i++)cout<<res[i]<<"\n";
}
