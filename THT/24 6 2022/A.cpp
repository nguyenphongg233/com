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

ll n,a,b,d;

signed main(){
	cin>>n>>a>>b>>d;
	ll sum = (n - a >= d) + (n - b >= d) + (b - 1 >= d) + (a - 1 >= d);
	
	ll l = n - a;
	ll r = n - b;
	if(l >= d)l = d - 1;
	if(r >= d)r = d - 1;
	if(l < r)swap(l,r);
	
	
	ll str = d - l;
	
	if(str <= r)sum += r - str + 1;
	
	
	
	
	l = n - a;
	r = b - 1;
	if(l >= d)l = d - 1;
	if(r >= d)r = d - 1;
	if(l < r)swap(l,r);
	
	
	str = d - l;
	
	if(str <= r)sum += r - str + 1;
	
	l = b - 1;
	r = a - 1;
	if(l >= d)l = d - 1;
	if(r >= d)r = d - 1;
	if(l < r)swap(l,r);
	
	str = d - l;
	
	if(str <= r)sum += r - str + 1;
	
	
	l = a - 1;
	r = n - b;
	if(l >= d)l = d - 1;
	if(r >= d)r = d - 1;
	if(l < r)swap(l,r);
	
	str = d - l;
	
	if(str <= r)sum += r - str + 1;
	
	
	cout<<sum<<"\n";
	
}