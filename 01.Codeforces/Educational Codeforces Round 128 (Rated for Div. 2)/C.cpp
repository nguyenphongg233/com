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

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		
		ll bit1 = 0,bit0 = 0;
		
		for(ll i = 0;i < s.size();i++){
			ll x = s[i] - '0';
			if(!x)bit0++;
		}
		ll n = s.size();
		s = " " + s;
		ll l = 1,r = n;
		ll res = INF;
		while(l <= r){
			while(s[l] == '0')l++,bit0--;
			while(s[r] == '0')r--,bit0--;
			
			res = min(res,max(bit1,bit0));
			if(s[l] == s[r] && s[l] == '1'){
				if(bit1 >= bit0)break;
				
				
				ll cntl = 0,l_ = l;
				ll cntr = 0,r_ = r;
				
				while(l_ <= r && s[l_] == '1')cntl++,l_++;
				while(r_ >= l_ && s[r_] == '1')cntr++,r_--;
				
				if(bit1 + cntl < bit0 && bit1 + cntr < bit0 && bit1 + cntr > bit1 + cntl){
					bit1 += cntl;
					l = l_;
				}else if(bit1 + cntl < bit0 && bit1 + cntr < bit0 && bit1 + cntl > bit1 + cntr){
					bit1 += cntr;
					r = r_;
				}else break;
				
				res = min(res,max(bit1,bit0));
			}
		}
		
		
		cout<<res<<"\n";
		
	}
}