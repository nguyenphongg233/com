#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll a[MAX];
ll l[MAX],r[MAX];

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		
		
		for(ll i = 1;i <= n;i++)cin>>a[i],l[i] = l[i - 1] + a[i];
		for(ll i = n;i >= 1;i--)r[i] = r[i + 1] + a[i];
		
		
		bool c = 0;
		
		for(ll i = 1;i <= n;i++){
			if(l[i] <= a[i] && l[i] >= r[i])continue;
			
			c = 1;
			break;
		}
		
		if(c)cout<<"No";
		else cout<<"Yes";
		
		cout<<"\n";
		
		
		
		
		
		
		
		
		
		for(ll i = 1;i <= n;i++)l[i] = r[i] = a[i] = 0;
		
	}
}