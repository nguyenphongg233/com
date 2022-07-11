#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e7 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;


ll a,b,c[MAX];

signed main(){
	cin>>a>>b;
	
	for(ll i = 2;i <= b + 1;i++){
		//c[i]++;
		
		ll d = i + i;
		
		for(;d <= b + 1;){
			c[d] += i;
			d += i;
		}
		
		
	}
	ll sum = 0;
	
	c[1]--;
	for(ll i = a;i <= b;i++){
		c[i]++;
		
		sum += abs(i - c[i]);
	}
	
	cout<<sum;
}