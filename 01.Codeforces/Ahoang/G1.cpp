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

ll cnt[N];
ll n,q;
ll a[MAX];
ll bit[MAX];
ll vitri,slg;
void update(ll id,ll v){
	for(;id > 0;id -= id&-id)bit[id] ^= v;
}

ll get(ll id){
	ll sum = 0;
	for(;id < MAX;id += id&-id)sum ^= bit[id];
	
	return sum;
}
signed main(){
	
	cin>>n>>q;
	
	
	vitri = n;
	slg = n;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		for(ll j = 0;(1 << j) <= a[i];j++){
			cnt[j] += (a[i] >> j) & 1;
		}
	}
	
	
	for(ll ie = 1,c,v;ie <= q;ie++){
		cin>>c>>v;
		
		if(c == 1){
			slg++;
			vitri++;
			
			a[vitri] = v;
			
			for(ll i = 0;(1 << i) <= v;i++){
				cnt[i] += (v >> i) & 1;
			}
		}else if(c == 2){
			
			//a[p] = 1;
			slg--;
			ll val = get(v) ^ a[v];
			for(ll i = 0;(1 << i) <= val;i++){
				cnt[i] -= (val >> i) & 1;
			}
			//a[v] = 0;
			
			
		}else if(c == 3){
			
			update(vitri,v);
			for(ll i = 0;(1 << i) <= v;i++){
				if(v >> i & 1)
				cnt[i] = slg - cnt[i];
			}
		}
		
		
		ll sum = 0;
		//cout<<slg<<"\n";
		for(ll i = 0;i < 32;i++)sum += cnt[i] * (1 << i);
		//cout<<"\n";
		cout<<sum<<"\n";
		
		
		
	}
	
}