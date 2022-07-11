#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k;
priority_queue<ll> minx;
// minx > 0
priority_queue<ll,vi,greater<ll>> maxx;
// maxx < 0
ll cnt0 = 0;
ll a[MAX];

bool cmp(ll a,ll b){
	return a > b;
}

void subnegative(){
	sort(a + 1,a + 1 + n,cmp);
	
	if(cnt0 >= k){
		cout<<0;
		return;
	}
	
	
	ll id = 1;
	while(a[id] == 0)id++;
	
	priority_queue<ll> h;
	for(ll i = 0;i < 3 * k;i++){
		h.push(a[i + id]);
	}
	ll sum = 0;
    for(ll i = 1;i <= k;i++){
    	if(i < k - cnt0 + 1){
    		ll x = h.top();
    		h.pop();
    		ll y = h.top();
    		h.pop();
    		ll z = h.top();
    		h.pop();
    		
    		sum += x * y * z;
    	}
    }
	cout<<sum;
}
signed main(){
	cin>>n>>k;
	
	bool lower = 0;
	
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		
		if(x < 0)maxx.push(x);
		else minx.push(x);
		
		if(x > 0)lower = 1;
		if(x == 0)cnt0++;
		a[i] = x;
	}
	
	if(!lower){
		subnegative();
		return 0;
	}
	
	ll sum = 0;
	
	for(ll i = 1;i <= k;i++){
		
		ll choose = -4;
		ll mx = -INF;
		if(maxx.size() >= 2 && minx.size() >= 1){
			
			ll x = maxx.top();
			maxx.pop();
			ll y = maxx.top();
			maxx.pop();
			ll z = minx.top();
			minx.pop();
			
			if(mx < x * y * z){
				mx = x * y * z;
				choose = 1;
			}
			
			maxx.push(x);
			maxx.push(y);
			minx.push(z);
			
		}
		
		// 2 - 1 +
		
		if(minx.size() >= 3){
			ll x = minx.top();
			minx.pop();
			ll y = minx.top();
			minx.pop();
			ll z = minx.top();
			
			if(mx < x * y * z){
				mx = x * y * z;
				choose = 2;
			}
			
			minx.push(x);
			minx.push(y);
		}
		
		// 3 + 
		
		if(minx.empty()){
			ll x = maxx.top();
			maxx.pop();
			ll y = maxx.top();
			maxx.pop();
			ll z = maxx.top();
			
			
			if(mx < x * y * z){
				mx = x * y * z;
				choose = 3;
			}
			
			maxx.push(x);
			maxx.push(y);
		}
		
		// 3 - 
		
		if(maxx.size() >= 1 && minx.size() >= 2){
			ll x = maxx.top();
			ll y = minx.top();
			minx.pop();
			ll z = minx.top();
			
			if(mx < x * y * z){
				mx = x * y * z;
				choose = 4;
			}
			
			minx.push(y);
			
		}
		
		
		
		// 2 + 1 -
		
		sum += mx;
		
		if(choose == 1){
			maxx.pop();
			maxx.pop();
			minx.pop();
		}else if(choose == 2){
			minx.pop();
			minx.pop();
			minx.pop();
		}else if(choose == 3){
			maxx.pop();
			maxx.pop();
			maxx.pop();
		}else if(choose == 4){
			maxx.pop();
			minx.pop();
			minx.pop();
		}
		
		
		
		
	}
	
	cout<<sum;
	
}
