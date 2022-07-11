#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll n;
	cin>>n;
	
	//if(n % 7 == 0)return cout<<n/7 * 2 <<" "<<n/7 * 2,0;
	ll dd = n / 7;
	ll du = n % 7;
	
	ll res = dd * 2;
	if(du >= 6)res++;
	
	ll res2 = dd * 2;
	
	if(du >= 1)res2++;
	if(du >= 2)res2++;
	
	cout<<res<<" "<<res2<<"\n";
}