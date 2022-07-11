#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll a,b,s;
ll last = 0;
signed main(){
	cin>>a>>b;
	
	for(ll i = 0;i < 64;i++){
		ll x = (a >> i ) & 1;
		ll y = (b >> i ) & 1;
		
		if(x == 1 && y == 1){
			if(last == 1)
			s = s ^ (1 << i);
			else last = 1;
		}else if(x ^ y == 1){
			if(last == 0){
				s = s ^ (1 << i);
			}
		}else if(x == 0 && y == 0){
			if(last == 1){
				last = 0;
				s = s ^ (1 << i);
			}
		}
		
		//cout<<s<<"\n";
	}
	
	cout<<s;
}