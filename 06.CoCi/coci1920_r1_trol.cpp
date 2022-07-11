#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll t;
ll pdt[MAX];

ll find(ll id){
	
	if(id <= 9)return id;
	
	string sf = to_string(id);
	
	ll sum = 0;
	
	for(ll i = 0;i < sf.size();i++)sum += sf[i] - '0';
	
	return find(sum);
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>t;
	
	
	
	while(t-- ){
		ll l,r;
		cin>>l>>r;
		
		if(r <= 9){
			cout<<(r - l + 1) * (r + l) / 2<<'\n';
		}else{
			ll sum = 0;
			
			for(ll i = l;i <= r;i++){
				sum += find(i);
				// find(i) : toi da O(3);
			}
			
			cout<<sum<<"\n";
		}
	}
}