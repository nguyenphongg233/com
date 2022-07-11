#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll a,b,c,n;

ll lcm(ll a,ll b){
	return a / __gcd(a,b) * b;
}

ll lcm1(ll a,ll b,ll c){
	return lcm(lcm(a,b),c);
}

signed main(){
	cin>>n>>a>>b>>c;
	
	cout<<n / a + n / b + n / c- n / (lcm(a,b)) - n /(lcm(b,c)) - n/(lcm(a,c))+ n / lcm1(a,b,c);
}