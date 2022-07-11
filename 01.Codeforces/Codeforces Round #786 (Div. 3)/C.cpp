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

ll pow2(ll a,ll b){
	if(b == 1)return a;
	ll s = pow2(a,b/2);
	
	s = s * s;
	
	if(b & 1)return s * a;
	else return s;
}

signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		string a,b;
		
		cin>>a>>b;
		
		bool check1 = 0,check2 = 0;
		
		for(ll i = 0;i < b.size();i++){
			if(b[i] == 'a')check1 = 1;
			else check2 = 1;
		}
		
		if(check1){
			if(b.size() > 1)cout<<-1<<"\n";
			else cout<<1<<"\n";
			continue;
		}
		
		ll n = a.size();
		ll m = b.size();
		
		ll cnt = 1;
		
		cout<<pow2(2,n)<<"\n";
		
	}
}