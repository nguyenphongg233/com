#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e7 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e7;

using namespace std;

ll n;
ll snt[MAX];
ll cnt[MAX];
ll cnt2[MAX];


ll power(ll a,ll b){
	
	if(b == 1)return a % mod;
	
	ll s =  power(a,b/2) % mod;
	
	s = (s * s) % mod;
	
	if(b & 1)s = (s * a) % mod;
	
	return s % mod;
	
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;

	
	memset(snt,-1,sizeof snt);
	
	snt[0] = 0;
	snt[1] = 1;
	
	for(ll i = 2;i * i < MAX;i++){
		if(snt[i] == -1){
			
			for(ll j = i * i;j < MAX;j += i)snt[j] = i;
			
		}
	}
	
	for(ll i = 2;i < MAX;i++)snt[i] = (snt[i] == -1) ? i : snt[i];
	
	for(ll i = 1;i <= n;i++){
		
		ll x;
		cin>>x;
		
		vi re;
		while(x != 1){
			
			ll y = snt[x];
			re.push_back(y);
			cnt2[y]++;
			x /= y;
			
		}
		
		if(re.empty())continue;
		sort(re.begin(),re.end());
		re.erase(unique(re.begin(),re.end()),re.end());
		for(auto v : re){
			//cout<<v<<" ";
			cnt[v] = max(cnt[v],cnt2[v]);
			cnt2[v] = 0;
			
		}
		//cout<<'\n';
		
		
	}
	
	ll res = 1;
	
	for(ll i = 2;i < MAX;i++){
		
		//cout<<snt[i]<<"\n";
		
		if(cnt[i] == 0)continue;
		
		
		ll x = cnt[i];
		ll y = (3 - (x % 3)) % 3;
		
		
		
		res = (res % mod * power(i,x + y) % mod) % mod;
		
		
	}
	
	cout<<res % mod;

	
	
	
	
}