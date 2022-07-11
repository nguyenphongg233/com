#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;


ll k,m,n,p;

ll a[MAX],b[MAX],c[MAX];
bool cmp(ll i,ll j){
	return b[i] - a[i] > b[j] - a[j];
}

ll ha[MAX],hb[MAX];
ll sumc = 0;
signed main(){
	
	
	cin>>m>>n>>p;
	
	k = m + n + p;
	
	vi huh(k);
	for(ll i = 1;i <= k;i++){
		cin>>a[i]>>b[i]>>c[i];
		huh[i - 1] = i;
		a[i] -= c[i];
		b[i] -= c[i];
		
		sumc += c[i];
	}
	
	sort(huh.begin(),huh.end(),cmp);
	
	priority_queue<ll> s,d;
	
	ll res = INF;
	
	ll suma = 0,sumb = 0;
	for(ll i = 0;i < k;i++){
		ll id = huh[i];
		
		suma += a[id];
		s.push(a[id]);
		
		if(s.size() > m)suma-=s.top(),s.pop();
		
		ha[i] = suma;
		
		
	}
	
	for(ll i = k - 1;i >= 0;i--){
		ll id = huh[i];
		
		sumb += b[id];
		d.push(b[id]);
		
		if(d.size() > n)sumb -= d.top(),d.pop();
		
		hb[i] = sumb;
	}
	
	for(ll i = m - 1;i < k - n;i++){
		res = min(res,ha[i] + hb[i + 1]);
	}
	
	cout<<res + sumc;
}