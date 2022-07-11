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

ll n,a[MAX],x;


signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	cin>>x;
	
	for(ll i = 1;i <= n;i++)a[i] -= x;
	
	
}