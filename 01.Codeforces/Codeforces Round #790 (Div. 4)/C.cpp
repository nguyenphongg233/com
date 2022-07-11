#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		string s[MAX];
		cin>>n>>m;
		for(ll i = 1;i <= n;i++){
			cin>>s[i];
		}
		
		ll res = INF;
		for(ll i = 1;i <= n;i++){
			for(ll j = i + 1;j <= n;j++){
				//cout<<s[i]<<" "<<s[j]<<"\n";
				ll sum = 0;
				for(ll z = 0;z < m;z++){
					sum += abs(s[j][z] - s[i][z]);
					//cout<<abs(s[j][z] - s[i][z])<<"\n";
				}
				res = min(res,sum);
			}
		}
		cout<<res<<"\n";
	}
}