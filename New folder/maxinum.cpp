#include<bits/stdc++.h>

const long long MAX = 1e6 + 5;
#define int long long 
#define ll long long 
const long long mod = 1e9 + 7;
using namespace std;

ll a[MAX];


find(int x,int y)
{
    if(x>y) return 1;
    ll ans = pow(a[x],find(x+1,y));
    ans %= mod;
    return ans;
}

signed main(){
	
	ll n;
	
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	
	cout<<find(70,80);
	
	
}