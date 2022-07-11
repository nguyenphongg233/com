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

ll d,t,b;

signed main(){
	cin>>d>>t>>b;
	
	if(b == 1){
		if(t == d)cout<<"Possible";
		else cout<<"Impossible";
		return 0;
	}
	
	if((d - t) % (b - 1) != 0)return cout<<"Impossible",0;

	ll x = (d - t) / (b - 1);
	
	if(x > t || x * b > d)return cout<<"Impossible",0;
	
	
	if(d - x * b != t - x)return cout<<"Impossible",0;
	
	
	cout<<"Possible";
	
}