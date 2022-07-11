#include<bits/stdc++.h>

#define ll long long 
#define vi vector<ll>
#define ii pair<ll,ll> 

#define X first
#define Y second

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n;
ll step = 0;

signed main(){
	cin>>n;
	
	while(n != 0){
		step++;
		
		string s = to_string(n);
		
		ll op = 0;
		for(ll i = 0;i < s.size();i++){
			ll o = s[i] - '0';
			op = max(op,o);
		}
		n-=op;
	}
	
	cout<<step;
}