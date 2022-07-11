#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;

		
		map<char,ll> cntl,cntr;
		map<string,ll> cntmid;
		
		ll sum = 0;
		
		for(ll i = 1;i <= n;i++){
			string s;
			cin>>s;
			
			sum += cntl[s[0]] + cntr[s[1]] - 2 * cntmid[s];
			
			cntl[s[0]]++;
			cntr[s[1]]++;
			cntmid[s]++;
		}
		
		cout<<sum<<"\n";
		
		
	}
}