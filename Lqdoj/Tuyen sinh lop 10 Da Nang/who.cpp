#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 15;

using namespace std;

signed main(){
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	
	if(a + b <= k || a + c <= k || c + b <= k)cout<<"YES\n";
	else cout<<"NO";
	
}