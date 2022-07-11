#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

bool snt[MAX];
ll n;
ll k;
signed main(){
	cin>>n>>k;
	for(ll i = 2;i * i < MAX;i++){
		if(!snt[i]){
			for(ll j = i * i;j < MAX;j += i)snt[j] = 1;
		}
	}
	
	ll cnt = 0;
	string s = "";
	for(ll i = 2;i < MAX;i++){
		
		if(cnt == n)break;
		
		if(!snt[i])
	        s += to_string(i),
	        cnt++;
	}
	
	cnt = 0;
	
	//cout<<s<<"\n";
	while(cnt < k){
		
		string r = "";
		
	    for(ll i = 0;i < s.size() - 1;i++){
			if(s[i] <= s[i + 1] && cnt < k)cnt++;
			else r += s[i];
		}
		
		r += s[s.size() - 1];
		
		s = r;
		//break;
		//cout<<s<<"\n";
		
	}
	
	cout<<s;
}