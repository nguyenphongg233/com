#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,a[MAX];
stack<ll> st;
deque<ll> h;
signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] >= i)h.push_back(i);
		else st.push_back(i);
	}
}