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
	string s;
	cin>>s;
	
	ll res = 0;
	ll sum = 0;
	for(ll i = 0;i < s.size();i++){
		if(s[i] == 'D')sum += res,res = 0;
		else res = res * 10 + s[i] - '0';
	}
	
	cout<<sum;
	
}