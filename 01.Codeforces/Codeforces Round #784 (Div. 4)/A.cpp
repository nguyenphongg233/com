#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	
	ll t;
	cin>>t;
	
	while(t--){
		ll a;
		cin>>a;
		
		if(a >= 1900)cout<<"Division 1";
		else if(a >= 1600 && a < 1900)cout<<"Division 2";
		else if(a >= 1400 && a < 1600)cout<<"Division 3";
		else cout<<"Division 4";
		
		cout<<"\n";
	}
	
}