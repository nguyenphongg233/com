#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 20 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m;
vii dio;
signed main(){
	cin>>n>>m;
	
	ll c1 = 0;
	
	for(ll i = 1,l,r;i <= m;i++){
		cin>>l>>r;
		
		if(l <= r){
		   dio.push_back({l,1});
		   dio.push_back({r + 1,-1});
		}else{
			c1++;
			swap(l,r);
			dio.push_back({l + 1,-1});
			dio.push_back({r,1});
		}
	}
	
	if(c1 != 0)dio.push_back({1,c1});
	dio.push_back({n,0});
	sort(dio.begin(),dio.end());
	ll p = dio.size();
	ll res = 0;
	ll pref = 0;
	ll ans;
	pref += dio[0].Y;
	for(ll i = 1;i < p;i++){
		//cout<<dio[i].X<<" ";
		
		cout<<pref<<" "<<dio[i].X<<" "<<dio[i].Y <<"\n";
		if(pref > res){
			res = pref;
			ans = dio[i].X - dio[i - 1].X + 1;
		}
	
		pref += dio[i].Y;
	}
	
	cout<<res<<" "<<ans;
}
