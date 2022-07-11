#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		
		
		if(m == 1){
			cout<<n<<"\n";
			continue;
		}
		
		
		ll sum = (((((m + 1) % mod ) * (m % mod)) / 2 * n) % mod + 1);
		if(m == 3)sum = (sum % mod + (n * 2) % mod) %mod;
		else if(m > 3)sum = (sum % mod + ((m + 1)%mod * (m - 2)%mod) / 2 * (n % mod)) % mod;
		cout<<sum<<"\n";
		
	}
}