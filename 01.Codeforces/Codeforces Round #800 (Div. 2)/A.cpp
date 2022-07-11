#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		
		ll res = abs(a - b);
		
		swap(a,b);
		ll cnta = 0;
		ll cntb = 0;
		
		for(ll i = 1;i <= a + b;i++){
			if(i & 1){
				if(cnta < a)cout<<1,cnta++;
				else cout<<0,cntb++;
			}else{
				if(cntb < b)cout<<0,cntb++;
				else cout<<1,cnta++;
			}
		}
		
		cout<<"\n";
	}
}