#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll n;
string s[MAX];
signed main(){
	cin>>n;
	
	ll sum = 0;
	for(ll i = 1;i <= n;i++){
		cin>>s[i];
		
		for(ll j = 0;j < s[i].size();j++){
			if(s[i][j] == 'A')sum += 4;
			else if(s[i][j] == 'K')sum += 3;
			else if(s[i][j] == 'Q')sum += 2;
			else if(s[i][j] == 'J')sum += 1;
		}
		
		
	}
	
	cout<<sum;
	
}