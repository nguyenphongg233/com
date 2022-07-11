#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n;
ll a[MAX], b[MAX];

void printt(char a,ll n){
	for(ll i = 1;i <= n;i++)cout<<a;
}

signed main(){

	cin >> n;
	for(ll i = 1;i <= n;i++) cin >> a[i];
	for(ll i = 1;i <= n;i++) cin >> b[i];
	
	
	if( a[n] != b[1]){
		printt('a',n);
		printt('b',n);
		return 0;
	}
	if( n == 2){
		if(a[2] == b[1])cout<<"abba";
		return 0;
	}


	cout << "ab";
	printt('a',n - 1);
	printt('b',n - 1);
	

	
}