#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 5e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll n,p,q,m;
ll a[MAX];

ll k;

deque<ll> maxx,minx;

signed main(){
	cin>>n>>p>>q>>m>>k;
	
	for(ll i = 1;i <= n;i++){
		a[i] = (p * i + q) % m;
	}
	
	ll ans = n;
	ll last = 1;
	
	for(ll i = 1; i <= n; i++){
		while(!maxx.empty()&&a[maxx.back()]<=a[i])maxx.pop_back();
		while(!minx.empty()&&a[minx.back()]>=a[i])minx.pop_back();
		maxx.push_back(i);
		minx.push_back(i);
		while(a[maxx.front()]-a[minx.front()]>k){
			if(maxx.front()>minx.front()){
				
				
                last = minx.front() + 1;
                minx.pop_front();
                
			}else if(minx.front()>maxx.front()){
				

			    last = maxx.front() + 1;
			    maxx.pop_front();
				
			}else break;
		}
		ans += (i- last);
	}
	
	cout<<ans;
}