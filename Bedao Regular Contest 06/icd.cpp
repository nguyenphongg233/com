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

ll n,a[MAX];

signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	
	ll sum = 0;
	for(ll i = 1;i <= n;i++){
		if(i == n)cout<<a[i] + sum<<" ";
		else{
			a[i] += sum;
			ll du = a[i] % (n - i);
			cout<<du<<" ";
			sum += a[i] / (n - i);
			
		}
	}
}
