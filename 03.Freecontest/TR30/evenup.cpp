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

ll n;
ll a[MAX];

signed main(){
	cin>>n;
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		a[i] = x % 2;
	}
	
	stack<ll> st;
	ll cnt = 0;
	for(ll i = 1;i <= n;i++){
		if(!st.empty()){
			if(st.top() == a[i])cnt += 2,st.pop();
			else st.push(a[i]);
		}else st.push(a[i]);
	}
	
	cout<<n - cnt;
}