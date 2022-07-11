#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll n,a[MAX];

signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	ll sum = a[n];
	ll res = 0;
	ll minx = a[n];
	for(ll i = n - 1;i >= 1;i--){
		minx = min(a[i],minx - 1);
		if(minx <= 0)return cout<<sum,0;
		
		sum += minx;
	}
	
	cout<<sum;
}