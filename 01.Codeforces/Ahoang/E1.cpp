#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;

ll x,y,a,b,m;




bool check(ll width){
	
	
	//cout<<width<<" ";
	ll cnta = x;
	ll cntb = y;
	
	for(ll i = 1;i <= m;i++){
		ll sum = 0;
		
		while(sum < width && (cnta > 0 || cntb > 0)){
			//cout<<sum<<"\n";
			/*if(sum + a > width && sum + b > width && cnta > 0 && cntb > 0)cntb--,sum += b;
			else if(sum + a > width && cnta > 0)cnta--,sum += a;
			else if(cnta <= 0 && cntb > 0)cntb--,sum += b;
			else if(cntb <= 0 && cnta > 0)cnta--,sum += a;
			else if(cnta > 0 && cntb > 0)cnta--,sum += a;
			else if(cnta <= 0 && cntb <= 0)return false;*/
			
			if(a > b && cnta > 0)cnta--,sum += a;
			else cntb--,sum+=b;
		}
		
		if(sum < width || cnta < 0 || cntb < 0)return false;
	}
	
	//cout<<width<<" "<<cnta<<" "<<cntb<<"\n";
	return true;
}

signed main(){
	cin>>x>>a>>y>>b>>m;
	
	if(a < b)swap(a,b),swap(x,y);
	
	ll l = 1,r = 150;
	ll ans;
	
	while(l <= r){
		ll mid = l + r >> 1;
		if(check(mid))l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	
	cout<<ans;
}