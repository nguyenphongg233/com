#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m,k;
ii a[MAX];
ll b[MAX],c[MAX];
map<ll,ll> mp;
ll cnt = 0;
ll res[MAX];

bool cmp(ii a,ii b){
	return a.X < b.X || (a.X == b.X && a.Y < b.Y);
}
signed main(){
	cin>>n>>m>>k;
	
	set<ll> uni;
	for(ll i = 1;i <= n;i++){
		cin>>b[i];
		uni.insert(b[i]);
	}
	
	for(ll i = 1;i <= m;i++)cin>>c[i];
	
	for(ll i = 1;i <= n;i++){
		ll val = c[b[i]];
		mp[b[i]]++;
		
		if(mp[b[i]] > 1){
			a[++cnt].X = val;
			a[cnt].Y = 1;
		}
	}
	
	for(ll i = 1;i <= m;i++){
		ll val = c[i];
		if(mp[i] == 0){
			a[++cnt].X = val;
			a[cnt].Y = -1;
		}
	}
	
	sort(a + 1,a + 1 + cnt,cmp);
	
	ll h = cnt,c = 0;
	stack<ll> st;
	
	for(ll i = 1;i <= h;i++){
		if(a[i].Y == 1){
			st.push(a[i].X);
		}
		if(a[i].Y == -1){
			if(st.empty())continue;
			ll u = st.top();
			st.pop();
			res[++c] = a[i].X - u;
		}
	}
	
	sort(res + 1,res + 1 + c);
	
	ll ans = 0;
	ll f = uni.size();
	
	if(k - f > c)return cout<<-1,0;
	
	for(ll i = 1;i <= k - f;i++)ans += res[i];
	
	cout<<ans;
}