#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vi a(n);
		ll sum = 0;
		for(auto &x : a)cin>>x,sum += x;
		sort(a.begin(),a.end());
		cout<<sum - a[0] * a.size()<<"\n";
	}
}