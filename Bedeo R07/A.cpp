#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;
 
using namespace std;

ll n;
ll a[MAX];
ll cnt[MAX];
signed main(){
	
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	sort(a + 1,a + 1 + n);
	
	cnt[1] = 1;
	ll sum = 1;
	
	for(ll i = 2;i <= n;i++){
		
		if(a[i] == a[i - 1])cnt[i] = cnt[i - 1];
		else cnt[i] = cnt[i - 1] + 1;
		
		sum += cnt[i];
		
		
	}
	
	cout<<sum;
	
}