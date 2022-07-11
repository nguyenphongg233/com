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

ll n,m;
ll a[MAX];
ll res = 0;
deque<ll> h;

struct cmp{
bool operator()(ll a,ll b){
	return a < b;
}
};

signed main(){
	cin>>n>>m;
	
	
	priority_queue<ll,vi,cmp> q;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	sort(a + 1,a + 1 + n);
	for(ll i = 2;i <= n;i++){
		res = max(res,abs(a[i] - a[i - 1]));
		h.push_back(abs(a[i] - a[i - 1]));
		// h - > thua can xoa 
		q.push(abs(a[i] - a[i - 1]));
	}
	if(n == m)return cout<<res,0;
	
	if(n > m){
		ll t = n - m;
		
		for(ll i = 1;i <= t;i++){
			if(h.size() >= 1){
				if(h.front() > h.back()){
					h.pop_front();
				}else {
					h.pop_back();
				}
			}
			
			
		}
		
		ll minx = 0;
		
		while(!h.empty()){
			//cout<<h.front()<<"\n";
			minx = max(minx,h.front());
			h.pop_front();
		}
		
		return cout<<minx,0;
	}
	
	ll t = m - n;
	
	
	
	for(ll i = 1;i <= t;i++){
		ll u = q.top();
		//cout<<u<<":\n";
		q.pop();
		
		if(u & 1){
			ll x = u/2;
			ll y = u/2 + 1;
			q.push(x);
			q.push(y);
		}else{
			q.push(u/2);
			q.push(u/2);
		}
		
	}
	
	ll minx = 0;
	
	while(!q.empty()){
		//cout<<q.top()<<"\n";
		minx = max(minx,q.top());
		q.pop();
	}
	
	cout<<minx;
		
	
}