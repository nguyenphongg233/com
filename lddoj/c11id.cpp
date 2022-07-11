#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll n,a[MAX];

signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	sort(a + 1,a + 1 + n);
	
	ll sum = 1;
	
	for(ll i = 1;i <= n;i++){
		sum *= ((a[i] - i + 1 > 0) ? a[i] - i + 1 : 1);
		sum %= mod;
	}
	cout<<sum % mod;
}