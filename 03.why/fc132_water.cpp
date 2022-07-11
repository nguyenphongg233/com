#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;


ll n,a[MAX],l[MAX],r[MAX],d[MAX];
ii p[MAX],q[MAX];

signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	a[0] = INF;
	d[0] = 0;
	ll top = 0;
	
	for(ll i = 1;i <= n;i++){
		while(a[i] > a[d[top]]){
			r[d[top]] = i;
			top--;
		}
		d[++top] = i;
	}
	
	d[0] = 0,top = 0;
	
	for(ll i = n;i >= 1;i--){
		while(a[i] > a[d[top]]){
			l[d[top]] = i;
			top--;
		}
		d[++top] = i;
	}
	
	
	p[1] = {a[1],1};
	
	for(ll i = 2;i <= n;i++){
		p[i] = p[i - 1];
		if(a[i] >= p[i].X)p[i] = {a[i],i};
	}
	
	q[n] = {a[n],n};
	
	for(ll i = n - 1;i >= 1;i--){
		q[i] = q[i + 1];
		if(a[i] >= q[i].X)q[i] = {a[i],i};
	}
	
	
	ll res = 0;
	
	for(ll i = 1;i <= n;i++){
		ll x = min(p[i].X,q[i].X);
		res += x - a[i];
	}
	
	ll ans = res;
	
	for(ll i = 1;i <= n;i++){
		if (a[i] < p[i].X && a[i] < q[i].X) continue;
    	if (a[i] >= p[i].X && a[i] >= q[i].X) continue;
    	ll tmp = res;
    	ll x = a[i] + 1;
    	
    	if (x <= p[i].X) tmp += i - l[i] - 1;
    	if (x <= q[i].X) tmp += r[i] - i - 1;
    	

   		ans = max(ans, tmp);
	}
	
	cout<<ans;
}