#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll l,r;
bool d[MAX];

void sub1(){
	ll sum = 0;
	memset(d,0,sizeof d);
	for(ll i = l;i <= r;i++){
		d[i] = 1;
		ll x = i;
		
		for(ll j = 2;j * j <= x;j++){
			if(x % j == 0)d[j] = 1,d[x / j] = 1;
		}
		
	}
	
	for(ll i = 1;i <= r;i++){
		//if(d[i])cout<<i<<"\n";
		sum += d[i] * i;
	}
	cout<<sum + 1;
}
void sub2(){
	
}
signed main(){
	
	cin>>l>>r;
	
	ll sum = 0;
	
	if(r - l <= 1000 || r <= 1000)sub1();
	else sub2();
	
	
}