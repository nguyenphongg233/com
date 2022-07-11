#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		deque<ll> a;
		
		for(ll i = 1,x;i <= n;i++){
			cin>>x;
			a.push_back(x);
		}
		
		deque<ll> b;
		b.push_front(-INF);
		
		bool can = 1;
		while(!a.empty()){
			
			//cout<<a.size()<<"\n";
			ll n = a.size();
			
			if(n & 1){
				ll u = a.front();
				if(u < b.back()){
					can = 0;
					break;
				}else{
					b.push_back(u);
				}
				a.pop_front();
			}else{
				ll t1 = a.front();
				a.pop_front();
				ll t2 = a.front();
				a.pop_front();
				
				if(t1 > t2)swap(t1,t2);
				
				if(b.back() > t1){
					can = 0;
					break;
				}else{
					b.push_back(t1);
					a.push_front(t2);
				}
			}
			
		}

		
		if(can)cout<<"YES";
		else cout<<"NO";
		
		cout<<"\n";
	}
}