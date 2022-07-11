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

ll a,b,c,k;

signed main(){
	cin>>a>>b>>c>>k;
	
	if(k >= a && k >= b && k >= c)return cout<<"YES",0;
	
	if(k < b)return cout<<"NO",0;
	
	// cho toan bo cuu sang song 
	
	if(k < a && k < c)return cout<<"NO",0;
	// khong the tro toan bo sang song cx 1 luc 
	
	cout<<"YES";
}